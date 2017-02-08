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
      $query = "select P_STUDENT.StudentName, P_STUDENT.StudentID from P_STUDENT, P_ENROLLMENT where P_STUDENT.StudentID=P_ENROLLMENT.StudentID and
P_ENROLLMENT.CourseID = ".$_POST["studentID_Detail"].";";
        echo "Student take Course with ID :".$_POST["studentID_Detail"];
      echo "<br>";
      $result = mysqli_query($dbconnection, $query);
      // Check if there is a query error
      if (!$result) {
         die("Database query failed.");
      }
   ?>
   <ul>
<table border="1" >
<tr>
<td> StudentName</td>
<td> StudentID</td>
</tr>
 <?php
      echo "--- Fetch the data ---";
      echo "<br>";
      // 3. Use returned result
      while ($row = mysqli_fetch_assoc($result)) {
         // output data from each row
?>
        <tr>
        <td><?php echo $row["StudentName"] ;?></td>
        <td><?php echo $row["StudentID"];?></td>

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
