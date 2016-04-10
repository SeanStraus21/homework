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
				<form action="matches-submit.php" method="get">
					<legend>Returning User:</legend>
					<label class=left for="name">Name:</label>
					<input type = "text" name ="name" size = 16/> <br>
					<br>
					<input type= "submit" value="View My Matches"/>
				</form>
			</div>
		</fieldset>
		<?php include 'bottom.html';?>
	</body>
</html>