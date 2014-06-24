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
        <link href="scripts/FooTable/css/footable.core.css" rel="stylesheet" type="text/css" />
        <link href="scripts/FooTable/css/footable.standalone.css" rel="stylesheet" type="text/css" />
        <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.9.1/jquery.min.js" type="text/javascript"></script>
        <script src="scripts/FooTable/js/footable.js" type="text/javascript"></script>
        <script src="scripts/FooTable/js/footable.paginate.js" type="text/javascript"></script>
        <script src="scripts/FooTable/js/footable.sort.js" type="text/javascript"></script>

    </head>
    <body>
        <?php
        $DBServer = 'localhost'; // e.g 'localhost' or '192.168.1.100'
        $DBUser = 'root';
        $DBPass = '';
        $DBName = 'gtest_cloud';
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
        <table class="footable metro-blue" data-page-size="5">
            <!-- Table Header -->
            <thead>
               <tr>
                    <th data-type="alpha">
                        User
                    </th>
                    <th data-type="alpha">
                        Machine Id
                    </th>
                    <th data-type="numeric" data-sort-initial="true">
                        Success Rate
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
                    $successRate = $row['successrate'];
                    ?>
                    <tr>
                        <td>
                            <?php echo $userId; ?>
                        </td>
                        <td>
                            <?php echo $machineId; ?>
                        </td>
                        <?php 
                        if($successRate==100)
                        {
                            echo "<td data-value='$successRate'> <span class='status-metro  status-good' title='Disabled'>Excellent</span>";
                        }
                        else if(($successRate>90)&&($successRate<99))
                        {                            
                            echo "<td data-value='$successRate'> <span class='status-metro status-fair' title='Disabled'>Fair</span>";
                        }
                        else
                        {
                            echo "<td data-value='$successRate'> <span class='status-metro status-bad' title='Disabled'>Bad</span>";
                        }
                        echo " [ ";
                        echo $successRate;
                        echo "% ] ";
                        ?>
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
<script type="text/javascript">
    $(function () {
        $('table').footable();
    });
</script>

    </body>
</html>
