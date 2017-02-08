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
      $query = "select T.TutorID, T.TutorName, T.TutorAddress, T.TutorPhone, T.TutorSalary, C.CourseID, sum(L.Duration) as 'Hours'
  from P_TUTOR as T, P_TUTOR_COURSE as C, P_TUTOR_LOG as L
  where T.TutorID = ".$_POST["tutorID_Detail"]." and T.TutorID=C.TutorID and T.TutorID=L.TutorID
  group by T.TutorID, T.TutorName, T.TutorAddress, T.TutorPhone, T.TutorSalary, C.CourseID; ";
        echo "Information of Tutor with ID : ".$_POST["tutorID_Deatil"];
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
<td> Tutor ID</td>
<td> Tutor Name</td>
<td> Tutor Address</td>
<td> Tutor Phone No.</td>
<td> Tutor Salary</td>
<td> Course ID</td>
</tr>
<?php
      echo "--- Fetch the data ---";
      echo "<br>";
      // 3. Use returned result
$totalHours;
      while ($row = mysqli_fetch_assoc($result)) {
         // output data from each row
?>
        <tr>
        <td><?php echo $row["TutorID"] ;?></td>
        <td><?php echo $row["TutorName"];?></td>
        <td><?php echo $row["TutorAddress"];?></td>
        <td><?php echo $row["TutorPhone"];?></td>
        <td><?php echo $row["TutorSalary"];?></td>
        <td><?php echo $row["CourseID"];?></td>
        <?php $totalHours =  $row["Hours"];?>
        <?php }?>
</tr>
</table>
    </ul>
<p>  Total Hours of Tutor:    <?php echo $totalHours;?> </p>

   <?php
      // 4. Release returned result
      mysqli_free_result($result);
   ?>
   <?php
      // 5. Close the database connection
      mysqli_close($dbconnection);
   ?>
</html>
