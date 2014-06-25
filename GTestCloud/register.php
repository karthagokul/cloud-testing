<html>
    <head>
        <title>User registration form</title>
        <link href="index_style.css" rel="stylesheet" type="text/css" />
    </head>
    <body>    
        <?php
        require_once("constants.php");
        if (!isset($_POST['submit'])) {
            ?>    <!-- The HTML registration form -->

            <form class="elegant-aero" action="<?= $_SERVER['PHP_SELF'] ?>" method="post">
                <h1>Register
                    <span>Please fill all the texts in the fields.</span>
                </h1>
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