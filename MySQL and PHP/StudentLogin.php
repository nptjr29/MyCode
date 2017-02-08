<!DOCTYPE HTML>
   <?php
      // 1. Create a database connection
      $dbhost = "ecsmysql";
      $dbuser = "cs332u12";
      $dbpass = "ooteepou";
      $dbname = "cs332u12";
      $dbconnection = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname);
      // Check if the connection is ok
      if (mysqli_connect_errno()) {
         die("Database connection failed: " .
         mysqli_connect_error() . " (" > mysqli_connect_errno() . ")" );
      }
   ?>
   <?php
      // 2. Perform database query
      $query = "insert into P_STUDENT_LOG values (".$_POST["studentPassword_Login"].", now(), ".$_POST["StudentDuration"]."); ";
      echo "Welcome to Bright Minds Success Center";
      echo "<br>";



if ($dbconnection->query($query) === TRUE) {
    echo "New record created successfully";
} else {
    echo "Error: " . $query . "<br>" . $dbconnection->error;
}

   ?>

   <?php
      // 5. Close the database connection
      mysqli_close($dbconnection);
   ?>
</html>
