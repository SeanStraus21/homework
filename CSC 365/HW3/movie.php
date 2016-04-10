<!DOCTYPE html>  
<html>
<!--
Sean Straus
Straus21
-->
<head>
	<meta charset = "utf-8"/>
	<title>Rancid Tomatoes</title>
	<link rel="stylesheet" type= "text/css" href="movie.css"></link>
	<title>Title Page</title>
	<link rel="icon" type="image/png" href="http://courses.cs.washington.edu/courses/cse190m/11sp/homework/2/rotten.gif">
</head>


<body background="http://courses.cs.washington.edu/courses/cse190m/11sp/homework/2/background.png" >
	<?php
	//declare variables
	//fetch parameter
	$movie = $_GET['film'];
	
	//get info
	$file = fopen($movie . "/info.txt", "r") or die("Unable to open file");
	$title = fgets($file);
	$year = fgets($file);
	$rating = fgets($file);
	fclose($file);
	if (rating < "60"){
		$icon = "http://www.cs.washington.edu/education/courses/cse190m/12sp/homework/3/rottenbig.png";
	}else{
		$icon = "http://www.cs.washington.edu/education/courses/cse190m/12sp/homework/3/freshbig.png";
	}
	
	//get image
	$image = $movie . "/overview.png";
	
	//get overview
	$overview = array();
	$file = fopen($movie . "/overview.txt", "r") or die("Unable to open file");
	while(!feof($file)){
		$temp = fgets($file);
		array_push($overview,$temp);
	}
	fclose($file);
	
	//reviews
	$reviews = array();
	$files = glob($movie . "/review*");
	for($i=0;$i<count($files);$i++){
		$file = fopen($files[$i],"r") or die("Unable to open file");
		$temp = fgets($file);
		array_push($reviews,$temp);
		$temp = fgets($file);
		array_push($reviews,$temp);
		$temp = fgets($file);
		array_push($reviews,$temp);
		$temp = fgets($file);
		array_push($reviews,$temp);
		fclose($file);
	}
	if(count($files) % 2 == 0){
		$len1 = $len2 = count($files) / 2;
	}else{
		$len1 = (count($files)-1)/2 + 1;
		$len2 = (count($files)-1)/2;
	}
	?>
	<div id=banner>
		<div id=banner-interior> 
			<img src=http://courses.cs.washington.edu/courses/cse190m/11sp/homework/2/banner.png alt="missing image">
		</div>
		<h1><?php echo$title?> (<?php echo$year?>)</h1>
	</div>
	<div id=main>
		<div id=reviews>
			<div id=reviewbar>
				<img src=<?php echo$icon?> alt="Rotten">
				<?php echo$rating?>%
			</div>
			<div id=columns>
				<div id=column>
					<?php
					for($i=0;$i<$len1;$i++){
						echo '<p id="p1">';
							echo '<img src="http://www.cs.washington.edu/education/courses/cse190m/12sp/homework/3/'.strtolower($reviews[$i*4 + 1]).'.gif';
							echo '" alt="'.$reviews[$i*4 + 1].'" />';
							echo $reviews[$i*4 + 0];
						echo '</p>';
						echo '<p id="p2">';
							echo '<img src="http://www.cs.washington.edu/education/courses/cse190m/12sp/homework/2/critic.gif" alt="Critic" />';
							echo $reviews[$i*4 + 2];
							echo "<br />";
							echo $reviews[$i*4 + 3];
						echo '</p>';
					}
					?>
				</div>
				<div id=column>
					<?php
					for($i=0;$i<$len2;$i++){
						echo '<p id="p1">';
							echo '<img src="http://www.cs.washington.edu/education/courses/cse190m/12sp/homework/3/'.strtolower($reviews[($i+$len1)*4 + 1]).'.gif';
							echo '" alt="'.$reviews[($i+$len1)*4 + 1].'" />';
							echo $reviews[($i+$len1)*4];
						echo '</p>';
						echo '<p id="p2">';
							echo '<img src="http://www.cs.washington.edu/education/courses/cse190m/12sp/homework/2/critic.gif" alt="Critic" />';
							echo $reviews[($i+$len1)*4 + 2];
							echo "<br />";
							echo $reviews[($i+$len1)*4 + 3];
						echo '</p>';
					}
					?>
				</div>
			</div>
		</div>
		<div id=sidebar>
			<img style=float:top-right src=<?php echo$image ?> alt="general overview" />
			<div id=sidebar-interior>
				<dl>
					<?php
					for($i=0; $i<count($overview); $i++){
						$temp = explode(":",$overview[$i]);
						echo "<dt>";
						echo $temp[0];
						echo ":</dt>";
						echo "<dd>";
						echo $temp[1];
						echo "</dd>";
					}
					?>
				</dl>
			</div>
		</div>
		<div style="clear: both;"></div>
		<div id=footer>(1-10) of 88</div>
	</div>
	<div style="clear: both;"></div>
	<div id=validators>
		<a href="https://webster.cs.washington.edu/validate-html.php"><img src="http://webster.cs.washington.edu/w3c-html.png" alt="Valid HTML5" /></a> <br />
		<a href="https://webster.cs.washington.edu/validate-css.php"><img src="http://webster.cs.washington.edu/w3c-css.png" alt="Valid CSS" /></a>
	</div>
</body>
</html>