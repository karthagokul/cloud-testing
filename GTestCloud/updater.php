<?php

include_once('./constants.php');

/** Updates the database with the data
 * @param string $userId User ID
 * @param string $machineId Machine ID
 * @param string $successrate Unit Test Success Rate
 */
function UpdateDataBase($userId, $machineId, $successrate, $country,$details) {

    global $DBServer, $DBName, $DBUser, $DBPass;
    $conn = new mysqli($DBServer, $DBUser, $DBPass, $DBName);
    // check connection
    if ($conn->connect_error) {
        trigger_error('Database connection failed: ' . $conn->connect_error, E_USER_ERROR);
        exit;
    }
    $date = date('Y-m-d H:i:s');
    $sql = "INSERT INTO test_data (userid, machineid,successrate,country,details,update_date) VALUES ('$userId','$machineId','$successrate','$country','$details','$date')";
    $rs = $conn->query($sql);

    if ($rs === false) {
        trigger_error('Wrong SQL: ' . $sql . ' Error: ' . $conn->error, E_USER_ERROR);
        exit;
    }

    $conn->autocommit(TRUE);
    $conn->close();

    echo "Success";  
    //echo $details;
}

if (isset($_GET["userid"]) && isset($_GET["machineid"]) && isset($_GET["country"]) && isset($_GET["successrate"]) && isset($_GET["details"])) {
    $userid = $_GET["userid"];
    $machineId = $_GET["machineid"];
    $country = $_GET["country"];
    $successrate = $_GET["successrate"];
    $details = $_GET["details"];
    UpdateDataBase($userid, $machineId, $successrate, $country,$details);
} else {
    echo "Failed";
    echo "Please Make Sure that you have all the parameters";
}
?>