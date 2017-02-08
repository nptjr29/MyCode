<!DOCTYPE HTML>
   <?php
      // 1. Create a database connection
      $dbhost = "ecsmysql";
      $dbuser = "cs332u12";
      $dbpass = "ooteepou";
      $dbname = "cs332u12";
      $dbconnection = mysqli_connect($dbhost, $dbuser, $dbpass,
$dbname);
      // Check if the connection is ok
      if (mysqli_connect_errno()) {
         die("Database connection failed: " .
         mysqli_connect_error() . " (" > mysqli_connect_errno() . ")" );
      }
   ?>
   <?php
      // 2. Perform database query
      $query = "SELECT P_COURSE.CourseID, CourseName, TutorName
from P_COURSE, P_TUTOR_COURSE, P_TUTOR where
P_COURSE.CourseID=P_TUTOR_COURSE.CourseID and
P_TUTOR.TutorID=P_TUTOR_COURSE.TutorID; ";
        echo "Avaliable course and tutor";
      echo "<br>";
      $result = mysqli_query($dbconnection, $query);
      // Check if there is a query error
      if (!$result) {
         die("Database query failed.");
      }
   ?>
   <ul>
<table border="1" >
 <?php
      echo "--- Fetch the data ---";
      echo "<br>";
      // 3. Use returned result
      while ($row = mysqli_fetch_assoc($result)) {
         // output data from each row
?>
        <tr>
        <td><?php echo $row["CourseID"] ;?></td>
        <td><?php echo $row["CourseName"];?></td>
        <td><?php echo $row["TutorName"]; ?></td>
        <?php }?>
</tr>
</table>
    </ul>
   <?php
      // 4. Release returned result
      mysqli_free_result($result);
   ?>
   <?php
      // 5. Close the database connection
      mysqli_close($dbconnection);
   ?>
</html>
