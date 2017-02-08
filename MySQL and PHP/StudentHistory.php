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
 $query = " select S.StudentName, S.StudentID, S.StudentAddress, S.StudentPhone, S.CurrentCourse, E.EnrollmentID, E.Semester, E.NumericGrade,
E.LetterGrade, sum(L.Duration) as 'Hours'
         from P_STUDENT as S, P_ENROLLMENT as E, P_STUDENT_LOG as L
         where S.StudentID= ". $_POST["studentID_History"]." and S.StudentID=E.StudentID and S.StudentID=L.StudentID
         group by S.StudentName, S.StudentID, S.StudentAddress, S.StudentPhone, S.CurrentCourse, E.EnrollmentID, E.Semester, E.NumericGrade,
E.LetterGrade;";

      echo"Get Student history with studentID : ".$_POST["studentID_History"]  ;
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
<td> Enrollment ID</td>
<td> Student Name</td>
<td> Student ID</td>
<td> Current Course ID</td>
<td> Semester</td>
<td> Address</td>
<td> Numeric Grade</td>
<td> Letter Grade</td>
<td> Phone </td>
<td> Total Hours</td>
</tr>
 <?php
      echo "--- Fetch the data ---";
      echo "<br>";
      // 3. Use returned result
      while ($row = mysqli_fetch_assoc($result)) {
         // output data from each row
?>
        <tr>
        <td><?php echo $row["EnrollmentID"] ;?></td>
        <td><?php echo $row["StudentName"] ;?></td>
        <td><?php echo $row["StudentID"];?></td>
        <td><?php echo $row["CurrentCourse"]; ?></td>
        <td><?php echo $row["Semester"]; ?></td>
         <td><?php echo $row["StudentAddress"]; ?></td>
        <td><?php echo $row["NumericGrade"]; ?></td>
        <td><?php echo $row["LetterGrade"]; ?></td>
  <td><?php echo $row["StudentPhone"]; ?></td>
<td><?php echo $row["Hours"]; ?></td>

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
