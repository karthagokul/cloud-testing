<html>
    <head>
        <title>Login</title>
        <link href="index_style.css" rel="stylesheet" type="text/css" />
    </head>
    <body>
        <?php
        if (!isset($_POST['submit'])) {
            ?>
            <form class="elegant-aero" action="<?= $_SERVER['PHP_SELF'] ?>" method="post">
                <h1>Login Form
                    <span>Please fill all the texts in the fields.</span>
                </h1>
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
                $_SESSION['username']=$username;
                header('Location: viewall.php');
            }
        }
        ?>        
    </body>
</html>