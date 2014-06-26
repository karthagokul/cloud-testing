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
        <title>GTest Cloud Web Registration</title>
        <link href="index_style.css" rel="stylesheet" type="text/css" />
    </head>
    <body>    
        <p class="aero_info"><a href="index.php">Home</a> </p>
        <?php
        require_once("constants.php");
        if (!isset($_POST['submit'])) {
            ?>    <!-- The HTML registration form -->

            <form class="elegant-aero" action="<?= $_SERVER['PHP_SELF'] ?>" method="post">
                <center><h1>GTest Cloud Registration </h1></center>
                <label>
                    <span>Username</span>
                    <input type="text" name="username" />
                </label>

                <label>
                    <span>Password</span>
                    <input type="password" name="password" />
                </label>

                <label>
                    <span>First name</span>
                    <input type="text" name="first_name" />
                </label>

                <label>
                    <span>Last Name</span>
                    <input type="text" name="last_name" />
                </label>

                <label>
                    <span>Email Address</span>
                    <input type="text" name="email" />
                </label>

                <label>
                    <span>&nbsp;</span> 
                    <input type="submit" name="submit" value="Register" />
                </label>    
            </form>
            <?php
        } else {
## connect mysql server
            global $DBServer, $DBName, $DBUser, $DBPass;
            $mysqli = new mysqli($DBServer, $DBUser, $DBPass, $DBName);
            # check connection
            if ($mysqli->connect_errno) {
                echo "<p>MySQL error no {$mysqli->connect_errno} : {$mysqli->connect_error}</p>";
                exit();
            }
## query database
            # prepare data for insertion
            $username = $_POST['username'];
            $password = $_POST['password'];
            $first_name = $_POST['first_name'];
            $last_name = $_POST['last_name'];
            $email = $_POST['email'];

            # check if username and email exist else insert
            $exists = 0;
            $result = $mysqli->query("SELECT username from users WHERE username = '{$username}' LIMIT 1");
            if ($result->num_rows == 1) {
                $exists = 1;
                $result = $mysqli->query("SELECT email from users WHERE email = '{$email}' LIMIT 1");
                if ($result->num_rows == 1)
                    $exists = 2;
            } else {
                $result = $mysqli->query("SELECT email from users WHERE email = '{$email}' LIMIT 1");
                if ($result->num_rows == 1)
                    $exists = 3;
            }

            if ($exists == 1)
                echo "<p>Username already exists!</p>";
            else if ($exists == 2)
                echo "<p>Username and Email already exists!</p>";
            else if ($exists == 3)
                echo "<p>Email already exists!</p>";
            else {
                # insert data into mysql database
                $sql = "INSERT  INTO `users` (`id`, `username`, `password`, `first_name`, `last_name`, `email`) 
                VALUES (NULL, '{$username}', '{$password}', '{$first_name}', '{$last_name}', '{$email}')";

                if ($mysqli->query($sql)) {
                    //echo "New Record has id ".$mysqli->insert_id;
                    echo "<p>Registred successfully!</p>";
                    echo "<p><a href='login.php'>Continue to Login</a></p>";
                } else {
                    echo "<p>MySQL error no {$mysqli->errno} : {$mysqli->error}</p>";
                    exit();
                }
            }
        }
        ?> 
    </body>
</html>