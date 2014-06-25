<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title>GCloud</title>
        <link href="index_style.css" rel="stylesheet" type="text/css" />
        <link rel="stylesheet" type="text/css" href="//cdn.datatables.net/1.10.0/css/jquery.dataTables.css">        

        <!-- jQuery -->
        <script type="text/javascript" charset="utf8" src="//code.jquery.com/jquery-1.10.2.min.js"></script>

        <!-- DataTables -->
        <script type="text/javascript" charset="utf8" src="//cdn.datatables.net/1.10.0/js/jquery.dataTables.js"></script>
        <!-- DataTables CSS -->
        <link rel="stylesheet" type="text/css" href="//cdn.datatables.net/1.10.0/css/jquery.dataTables.css">

        <link rel="stylesheet" href="//code.jquery.com/ui/1.10.4/themes/smoothness/jquery-ui.css">
        <script src="//code.jquery.com/ui/1.10.4/jquery-ui.js"></script>   

        <script>
            $(document).ready(
                    function() {
                        $('#global_data').DataTable();
                        $(".moreinfo_dialog").dialog({
                            autoOpen: false,
                            height: "auto",
                            width: "600",
                            draggable: "true",
                            title: "More Information",
                        });

                    }
            )

            function onMoreInfoClick(value) {
                $(".moreinfo_dialog").html(value);
                $(".moreinfo_dialog").dialog("open");
            }

        </script>

    </head>
    <body>
        <?php
        include_once('./constants.php');
        global $DBServer, $DBName, $DBUser, $DBPass;
        $conn = new mysqli($DBServer, $DBUser, $DBPass, $DBName);

        if ($conn->connect_error) {
            trigger_error('Database connection failed: ' . $conn->connect_error, E_USER_ERROR);
        }

        $sql = "SELECT * FROM test_data";
        $rs = $conn->query($sql);

        if ($rs === false) {
            trigger_error('Wrong SQL: ' . $sql . ' Error: ' . $conn->error, E_USER_ERROR);
        } else {
            $rows_returned = $rs->num_rows;
        }
        //
        ?>
        <div class="moreinfo_dialog"></div>
    <center><span class="boldme iambigger colormered"> Recent Entries </span></center>
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
                <th align="left">
                    Details
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
                    <td style="white-space: normal; width:300px;">
                        <?php
                        $out =preg_replace('/\v+|\\\[rn]/','<br/>',$details);
                        ?>
                        <script language="javascript" type="text/javascript">
                            var details = "<?php echo $out; ?>";
                        </script>
                        <div onclick="onMoreInfoClick(details);">Click Here</div>
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
