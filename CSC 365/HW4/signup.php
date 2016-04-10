<!DOCTYPE html>
<html>
	<!--
	Sean Straus
	Straus21
	-->
	<head>
	<link href="nerdluv.css" type="text/css" rel="stylesheet" />
	</head>
	
	<body>
		<?php include 'top.html';?>
		<fieldset>
			<div>
				<form action="signup-submit.php" method="post">
					<legend>New User Signup:</legend>
					<label class=left for="name">Name:</label>
					<input type = "text" name ="name" size = 16/> <br>
					<label class=left for="gender">Gender:</label>
					<input type = "radio" name ="gender" value = "male" /> Male
					<input type = "radio" name ="gender" value = "female"/> Female<br>
					<label class=left for="age">Age:</label>
					<input type = "text" name ="age"  size = 4 maxlength=2/><br>
					<label class=left for="personality">Personality:</label>
					<input type = "text" name ="personality"  size = 6 maxlength=4 />
					<a href="http://www.humanmetrics.com/cgi-win/JTypes2.asp">Don't know your type?</a><br>
					<label class=left for="favos">Favorite OS:</label>
					<select name="favos">
						<option value = "windows"> Windows </option>
						<option value = "mac"> Mac OS X </option>
						<option value = "linux"> Linux </option>
					</select><br>
					<label class=left for="seekage_min">Seeking Age:</label>
					<input type = "text" name ="seekage_min"  size = 4 maxlength=2 placeholder = "min"/>
					to <input type = "text" name ="seekage_max"  size = 4 maxlength=2 placeholder = "max"/><br>
					<br>
					<input type="submit" value="Sign Up" />
				</form>
			</div>
		</fieldset>
		<?php include 'bottom.html';?>
	</body>
</html>
