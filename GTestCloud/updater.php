<?php

/** Updates the database with the data
 * @param string $userId User ID
 * @param string $machineId Machine ID
 * @param string $successrate Unit Test Success Rate
 */
function UpdateDataBase($userId, $machineId, $successrate) {

    $DBServer = 'localhost'; // e.g 'localhost' or '192.168.1.100'
    $DBUser = 'root';
    $DBPass = '';
    $DBName = 'gtest_cloud';

    $conn = new mysqli($DBServer, $DBUser, $DBPass, $DBName);
    // check connection
    if ($conn->connect_error) {
        trigger_error('Database connection failed: ' . $conn->connect_error, E_USER_ERROR);
        exit;
    }

    $sql = "INSERT INTO test_data (userid, machineid,successrate) VALUES ('$userId','$machineId','$successrate')";
    $rs = $conn->query($sql);

    if ($rs === false) {
        trigger_error('Wrong SQL: ' . $sql . ' Error: ' . $conn->error, E_USER_ERROR);
        exit;
    }

    echo "SuccessFully Updated";
    echo "<br>";
    echo "Summary";
    echo "<br>";
    echo $userId;
    echo "<br>";
    echo $machineId;
    echo "<br>";
    echo $successrate;

    $conn->autocommit(TRUE);
    $conn->close();
}

if (isset($_GET["userid"]) && isset($_GET["machineid"]) && isset($_GET["successrate"])) {
    $userid = $_GET["userid"];
    $machineId = $_GET["machineid"];
    $successrate = $_GET["successrate"];
    UpdateDataBase($userid, $machineId, $successrate);
} else {
    echo "Invalid Request!";
}
?>