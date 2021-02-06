
<?php

//Jesús Arturo Araiza Grijalva
//1CV1
$im=imagecreatefromjpeg('lesion.jpg');   //imagecreatefromjpeg, hay para muchos tipos, es como un apuntador para la imagen.
$ancho=imagesx($im); //imagesx determina el ancho de una imagen
$largo=imagesy($im); //imagesy determina el largo de una imagen 
echo ("<h1><center>hola mundo</center></h1>");

echo ("<b><center>ancho=$ancho y largo=$largo</b><center>");

$tiempo_ini=microtime(true); //calcula el tiempo en milisegundos



$fp=fopen("datos.csv","w");


for($x=0;$x<$ancho;$x++)
	for($y=0;$y<$largo;$y++)
	{
		$indice=imagecolorat($im,$x,$y); //extrae el RGBA de ese pixel pero cifrado o algo asi.
		$rgb=imagecolorsforindex($im,$indice); 
		$R=$rgb['red'];            //Desde esta linea hasta la 33 es lo mismo que el print_r pero con una mejor presentación y mas personalizable.
		$G=$rgb['green'];
		$B=$rgb['blue'];
		$A=$rgb['alpha'];
		echo"<br> $R, $G, $B, $A";
		$cad="$x;$y;$R;$G;$B;$A \n";
		fputs($fp,"$cad");
		//print_r($rgb);  //El print_r le da una forma de presentación, 
		//echo"<br>";
		$nR=255-$rgb['red'];
		$nG=255-$rgb['green'];
		$nB=255-$rgb['blue'];
		$color=imagecolorallocate($im,$nR,$nG,$nB);
		imagesetpixel($im,$x,$y,$color);
		imagejpeg($im,'inverso.jpg',100);
		
	}
	echo"<br>";
fclose($fp);
	
$tiempo_fin=microtime(true); //calcula el tiempo en milisegundos

echo "Tiempo inicial=" .$tiempo_ini;

echo "<br>Tiempo final=".$tiempo_fin;

echo "<br>Tiempo=" .($tiempo_fin-$tiempo_ini). "<br>"; //imprime el tiempo que tarda en hacer todo restando el tiempo final al inicial.
?>

