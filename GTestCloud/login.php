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
        <title>GTest Cloud Web Login</title>
        <link href="index_style.css" rel="stylesheet" type="text/css" />
    </head>
    <body>
        <p class="aero_info"><a href="index.php">Home</a> </p>
        <?php
        if (!isset($_POST['submit'])) {
            ?>
            <form class="elegant-aero" action="<?= $_SERVER['PHP_SELF'] ?>" method="post">
                <center><h1>Login to GTest Cloud</h1></center>
                <label>
                    <span>User Name :</span>
                    <input type="text" name="username" />
                </label>

                <label>
                    <span>Password :</span>
                    <input type="password" name="password" />
                </label>

                <label>
                    <span>&nbsp;</span> 
                    <input type="submit" name="submit" value="Login" />
                </label>    
            </form>
            <?php
        } else {
            require_once("./constants.php");
            global $DBServer, $DBName, $DBUser, $DBPass;
            $mysqli = new mysqli($DBServer, $DBUser, $DBPass, $DBName);
            # check connection
            if ($mysqli->connect_errno) {
                echo "<p>MySQL error no {$mysqli->connect_errno} : {$mysqli->connect_error}</p>";
                exit();
            }

            $username = $_POST['username'];
            $password = $_POST['password'];

            $sql = "SELECT * from users WHERE username LIKE '{$username}' AND password LIKE '{$password}' LIMIT 1";
            $result = $mysqli->query($sql);
            if (!$result->num_rows == 1) {
                echo "<p>Invalid username/password combination</p>";
            } else {
                echo "<p>Logged in successfully</p>";
                session_start();
                $_SESSION['username'] = $username;
                header('Location: viewall.php');
            }
        }
        ?>        
    </body>
</html>