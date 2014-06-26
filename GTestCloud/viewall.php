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
        <title>GTest Cloud User Home</title>
        <link href="index_style.css" rel="stylesheet" type="text/css" />
        <link rel="stylesheet" type="text/css" href="//cdn.datatables.net/1.10.0/css/jquery.dataTables.css">        

        <!-- jQuery -->
        <script type="text/javascript" charset="utf8" src="//code.jquery.com/jquery-1.10.2.min.js"></script>

        <!-- DataTables -->
        <script type="text/javascript" charset="utf8" src="//cdn.datatables.net/1.10.0/js/jquery.dataTables.js"></script>
        <!-- DataTables CSS -->
        <link rel="stylesheet" type="text/css" href="//cdn.datatables.net/1.10.0/css/jquery.dataTables.css">

        <script>
            $(document).ready(
                    function() {
                        $('#global_data').DataTable();
                    }
            )
        </script>

    </head>
    <body>
        <?php
        include_once('./constants.php');
        global $DBServer, $DBName, $DBUser, $DBPass;
        $conn = new mysqli($DBServer, $DBUser, $DBPass, $DBName);
        session_start();
        $user = $_SESSION['username'];
        ?>
        <p class="aero_info"><?php echo "You have Logged in as $user"; ?> | <a href="completelog.php">View Complete Log</a> | <a href="logout.php">Logout</a> </p>
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
        <div class="moreinfo_dialog"></div>
    <center><p class="aero_para_bold"> Recent Entries </p></center>
    <table id="global_data" class="display">
        <!-- Table Header -->
        <thead>
            <tr>
                <th align="left">
                    User
                </th>
                <th align="left">
                    Machine Id
                </th>
                <th align="left">
                    Country
                </th>
                <th align="left" data-type="numeric">
                    Success Rate
                </th>
                <th align="left" data-type="numeric">
                    Date
                </th>
            </tr>

        </thead>
        <!-- Table Header -->
        <tbody>
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
                ?>
                <tr >
                    <td>
                        <?php echo $userId; ?>
                    </td>
                    <td>
                        <?php echo $machineId; ?>
                    </td>
                    <td>
                        <?php echo $country; ?>
                    </td>
                    <?php
                    if ($successRate == 100) {
                        echo "<td data-value='$successRate'> <span class='status-metro  status-good' title='Disabled'>Very Good</span>";
                    } else if (($successRate > 90) && ($successRate < 99)) {
                        echo "<td data-value='$successRate'> <span class='status-metro status-fair' title='Disabled'>Good</span>";
                    } else {
                        echo "<td data-value='$successRate'> <span class='status-metro status-bad' title='Disabled'>Bad</span>";
                    }
                    echo " [ ";
                    echo $successRate;
                    echo "% ] ";
                    ?>
                    </td>
                    <td>
                        <?php echo $update_date; ?>
                    </td>   
                </tr>
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
