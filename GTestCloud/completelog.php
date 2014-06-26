<!DOCTYPE html>
<!--
 Copyright (C) <2014>  Gokul Kartha <kartha.gokul@gmail.com>

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title>GTest Cloud Complete Log</title>
        <link href="index_style.css" rel="stylesheet" type="text/css" />
        <link rel="stylesheet" type="text/css" href="//cdn.datatables.net/1.10.0/css/jquery.dataTables.css">        

        <!-- jQuery -->
        <script type="text/javascript" charset="utf8" src="//code.jquery.com/jquery-1.10.2.min.js"></script>

    </head>
    <body>
        <?php
        include_once('./constants.php');
        global $DBServer, $DBName, $DBUser, $DBPass;
        $conn = new mysqli($DBServer, $DBUser, $DBPass, $DBName);
        session_start();
        $user = $_SESSION['username'];
        ?>
        <p class="aero_info"><?php echo "You have Logged in as $user"; ?> | <a href="viewall.php">Brief View</a> | <a href="logout.php">Logout</a></p>
        <?php
        if ($conn->connect_error) {
            trigger_error('Database connection failed: ' . $conn->connect_error, E_USER_ERROR);
        }

        //Let's check whether he is an admin if so show everything or else specific to the user
        if ($user == "admin")
            $sql = "SELECT * FROM test_data";
        else
            $sql = "SELECT * FROM `test_data` WHERE userid = '$user' ORDER BY `update_date` DESC ";
        $rs = $conn->query($sql);

        if ($rs === false) {
            trigger_error('Wrong SQL: ' . $sql . ' Error: ' . $conn->error, E_USER_ERROR);
        } else {
            $rows_returned = $rs->num_rows;
        }
        //
        ?>
        <br></br>
        <?php
        $rs->data_seek(0);
        while ($row = $rs->fetch_assoc()) {
            //echo $row['col1'] . '<br>';
            $userId = $row['userid'];
            $machineId = $row['machineid'];
            $country = $row['country'];
            $successRate = $row['successrate'];
            $update_date = $row['update_date'];
            $details = $row['details'];

            echo "<p class='aero_para'>";
            echo $update_date;
            echo "</p>";
            echo "<p class='aero_info'>";
            echo "User Id : " . $userId;
            echo "<br>";
            echo "Device Id : " . $machineId;
            echo "<br>";
            echo "Country : " . $country;
            echo "<br>";
            echo "Success Rate : " . $successRate;
            echo "<br>";
            $out = preg_replace('/\v+|\\\[rn]/', '<br/>', $details);
            echo "Test Log Follows";
            echo "</p><div class='aero_log'>";
            echo $out;
            echo "</div><hr>";
            ?>
            <?php
        }
        $conn->close();
        ?>
    </tbody>
<tfoot>
    <tr>
        <td colspan="5">
            <div class="pagination pagination-centered"></div>
        </td>
    </tr>
</tfoot>
</body>
</html>
