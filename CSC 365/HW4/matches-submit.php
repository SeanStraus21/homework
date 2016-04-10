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
		<?php
		$name = $_GET["name"];
		//0=name, 1=sex, 2=age, 3=personality, 4=favos, 5=minage, 6=maxage
		$singles = array();//create an array from singles.txt
		$file = fopen("singles.txt","r") or die("Unable to open file");
		while (!feof($file)){
			$temp = fgets($file);
			array_push($singles,$temp);
		}
		fclose($file);
		//get user profile
		$err_flag = true;
		for($i=0;$i<count($singles);$i++){
			$buffer = explode(",",$singles[$i]);
			if ($buffer[0] == $name){
				//save variables
				$sex = $buffer[1];
				$age = $buffer[2];
				$personality = $buffer[3];
				$favos = $buffer[4];
				$minage = $buffer[5];
				$maxage = $buffer[6];
				$err_flag = false;
				break;
			}
		}
		if ($err_flag){
			echo "!!!PROFILE NOT FOUND";
		}
		//find matches
		$matches = array();
		for ($i=0;$i<count($singles);$i++){
			$buffer = explode(",",$singles[$i]);
			//0=name, 1=sex, 2=age, 3=personality, 4=favos, 5=minage, 6=maxage
			if ($buffer[1] != $sex){
				if($buffer[2] <= $maxage && $buffer[2] >= $minage){
					$p1 = str_split($buffer[3]);
					$p2 = str_split($personality);
					$differences = 0;
					for($j=0;$j<4;$j++){
						if ($p1[$j] != $p2[$j]){
							$differences++;
						}
					}
					if($differences < 4){//if personality difference is less than 4
						if($buffer[4] == $favos){//if buffer.os = favos
							if($age >= $buffer[5] && $age <= $buffer[6]){// if age >= minage, age <=maxage
								array_push($matches,$singles[$i]);
							}
						}
					}
				}
			}
		}
		
		?>
		
		<?php include 'top.html';?>
		<h1>Matches for <?php echo($name);?></h1>
		<?php
		for($i=0;$i<count($matches);$i++){
			$buffer = explode(",",$matches[$i]);
			
			echo "<div class=match>";
			echo "<p class=match>";
				echo "<img class=match src='http://www.cs.washington.edu/education/courses/cse190m/12sp/homework/4/user.jpg' alt='user'>";
				echo $buffer[0];
			echo "</p>";
			echo "<ul><strong>";
			echo "<li>gender:</li>";
			echo "<li>age:</li>";
			echo "<li>type:</li>";
			echo "<li>OS</li>";
			echo "</column>";
			echo "</strong></ul>";
			echo "<ul>";
				echo "<li>".$buffer[1].",</li>";
				echo "<li>".$buffer[2]."</li>";
				echo "<li>".$buffer[3]."</li>";
				echo "<li>".$buffer[4]."</li>";
			echo "</ul>";
			echo "</div>";
			echo "<br>";
			
		}
		?>
		<?php include "bottom.html";?>
	</body>
</html>