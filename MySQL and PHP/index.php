<!DOCTYPE html>
<html lang="en">
<head>
        <meta charset="utf-8">
        <title>Bright Minds Center</title>
        <link rel="stylesheet" type="text/css" href="mainLayout.css">
        <!--[if lt IE 9]>
                <script src="http://html5shim.googlecode.com/svn/trunk/html5.js"></script>
        <![endif]-->
</head>
<div id="layout">
    <body>
            <main>
                    <header>
                            <h1>WELCOME TO BRIGHT MINDS CENTER</h1>
                            <p class="headInfo">Mathematics Tutoring Center:</p>
                            <p class="headInfo">Algebra, Trigonometry, Calculus, Linear Algebra, Discrete Math, and more!</p>
                    </header>
                    <!--This hold login for student and teacher></!-->
                    <div id="inputBox">
                    <div class="formBox" id="formAreaOne">
                        <form id="formArea" action="StudentLogin.php" method="post">
                            <p class="formTitle">Student Session</p>
                            <p>Student ID : <input type="text"
name="studentPassword_Login"></p>
                            <p>Duration : <input type="text" name="StudentDuration"></p>
                            <input type="submit">
                        </form>
                    </div>

                    <div class="formBox" id="formAreaTwo">
                        <form id="formArea" action="TutorLogin.php" method="post">
                            <p class="formTitle">Tutor Session</p>
                            <p>Tutor ID : <input type="text" name="tutorPassword_Login"></p>
                            <p>Duration : <input type="text" name="TutorDuration"></p>
                            <input type="submit">
                        </form>
                    </div>

                    <!--This hold login for student and teacher></!-->
                    <div class="formBox" id="formAreaThree">
                        <form id="formArea" action="StudentHistory.php" method="post" center>
                                <p class="formTitle">Get Student Information</p>
                                <p>Student ID: <input type="text" name="studentID_History"></p>
                                <input type="submit">
                        </form>
                    </div>

                    <div class="formBox" id="formAreaFour">
                        <form id="formArea" action="FindTutor.php" method="post">
                            <p class="formTitle">Get Tutor Information</p>
                            <p>Tutor ID : <input type="text" name="tutorID_Detail"></p>
                            <input type="submit">
                        </form>
                    </div>


                    <div id="studentHistoryForm">
                        <form id="formArea" action="FindStudent.php" method="post">
                            <p class="formTitle">Course Roster</p>
                            <p>Course ID : <input type="text" name="studentID_Detail"></p>
                            <input type="submit">
                        </form>
                    </div>
                  </div>
            </main>

        <br>
        <!-- This is for credit, which hold name of all member> </!-->
        <div id="phpBox">
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
              echo "Available Courses and Tutors";
            echo "<br>";
            $result = mysqli_query($dbconnection, $query);
            // Check if there is a query error
            if (!$result) {
               die("Database query failed.");
            }
          ?>
          <ul>
          <table align="center" border="1" >
          <tr>
          <td>Course ID</td>
          <td>Course Name</td>
          <td>Tutor Name</td>

          </tr>
          <?php
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
        </div>

            <footer>
                    <p>Created by: William, Kien, Trang, Thao, Noe</p>
            </footer>
    </body>
</div>
</html>
