<?php

/* Copyright (C) <2014>  Gokul Kartha <kartha.gokul@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
**/

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

/** Checks whether the particular user exists
 * @param string $userId User ID
 * @return bool if exists true else false
 */
function checkUser($userId)
{
    $userExists=true;
    global $DBServer, $DBName, $DBUser, $DBPass;
    $conn = new mysqli($DBServer, $DBUser, $DBPass, $DBName);
    // check connection
    if ($conn->connect_error) {
        trigger_error('Database connection failed: ' . $conn->connect_error, E_USER_ERROR);
        exit;
    }
    $sql = "SELECT * from users WHERE username LIKE '{$userId}' LIMIT 1";
    $result = $conn->query($sql);
    if (!$result->num_rows == 1) {
        $userExists=false;
    }
    $conn->close();
    return $userExists;
}

if (isset($_GET["userid"]) && isset($_GET["machineid"]) && isset($_GET["country"]) && isset($_GET["successrate"]) && isset($_GET["details"])) {
    $userid = $_GET["userid"];
    $machineId = $_GET["machineid"];
    $country = $_GET["country"];
    $successrate = $_GET["successrate"];
    $details = $_GET["details"];
    
    //Let's Check whether the user exists
    if(checkUser($userid))
    {
        UpdateDataBase($userid, $machineId, $successrate, $country,$details);
    }
    else
    {
        echo "Failed";
        echo "Invalid User";
    }
    
} else {
    echo "Failed";
    echo "Please Make Sure that you have all the parameters";
}
?>