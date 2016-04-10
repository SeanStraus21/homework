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
		
		<?php include 'top.html'; ?>
				
		<?php
			$name = $_POST["name"];
			$gender = $_POST["gender"];
			$age = $_POST["age"];
			$personality = $_POST["personality"];
			$favos = $_POST["favos"];
			$seekage_min = $_POST["seekage_min"];
			$seekage_max = $_POST["seekage_max"];
			
			if (is_writable("singles.txt")){
				$file = fopen("singles.txt","a") or die("Unable to open file");
				fwrite($file,"\r\n");
				fwrite($file,$name);
				fwrite($file,",");
				fwrite($file,$gender);
				fwrite($file,",");
				fwrite($file,$age);
				fwrite($file,",");
				fwrite($file,$personality);
				fwrite($file,",");
				fwrite($file,$favos);
				fwrite($file,",");
				fwrite($file,$seekage_min);
				fwrite($file,",");
				fwrite($file,$seekage_max);
				fclose($file);
			}else{
				echo "file not writable";
			}
		?>
		
		<h1>Thank You!</h1><br>
		<p> 
		Welcome to NerdLuv, <?php echo $name;?>!<br>
		Now <a href=matches.php>log in to see your matches!</a>
		</p>
		
		<?php include 'bottom.html'; ?>
		
	</body>
</html>