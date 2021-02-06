<html>
<!--Autor: Jesús Arturo Araiza Grijalva
Descripción: Es un programa que checa igualdades entre dos expresiones, pero lo complicado es que el usuario ingresa los operadores en la caja de texto.
Fecha: 30/Nov/16
Grupo: 1CV1-->
<body>
<style>
body{
	background-image: url("back.jpg");
}
/*css para firma*/
.firma{
	position: absolute;
	right: 50px;
	bottom: 10px;
}
/*ccs para centrar el texto "expresion 1" y "expresion 2"*/
.exp1{
	position: absolute;
	right:730px;
	width: 100px;
	padding: 0px;
}
.exp2{
	position: absolute;
	right:530px;
	width: 100px;
	padding: 0px;
}

/*Estilo de la cajita de alerta*/
.alert {
    padding: 20px;
    background-color: #008CBA; 
    color: white;
    margin-bottom: 15px;
	opacity: 1;
    transition: opacity 0.6s;
}

/*el boton de cerrar de la alerta*/
.closebtn {
    margin-left: 15px;
    color: white;
    font-weight: bold;
    float: right;
    font-size: 22px;
    line-height: 20px;
    cursor: pointer;
    transition: 0.3s;
}

/* CUando ponemos el mouse sobre la X de cerrar*/

.closebtn:hover {
    color: black;
}

/* Estilo de las pestañas */
ul.tab {
    list-style-type: none;
    margin: 0;
    padding: 0;
    overflow: hidden;
    border: 1px solid #ccc;
    background-color: #f1f1f1;
}

/* Que las pestañas esten de lado */
ul.tab li {float: left;}

/* Estilo a los links dentro de pestañas */
ul.tab li a {
    display: inline-block;
    color: black;
    text-align: center;
    padding: 14px 16px;
    text-decoration: none;
    transition: 0.3s;
    font-size: 17px;
}

/* Cambiar el color cuando se pasa el mouse por encima */
ul.tab li a:hover {background-color: #ddd;}

/* Crear una clase de tabs */
ul.tab li a:focus, .active {background-color: #ccc;}

/* Estilo al contenido de las tabs */
.tabcontent {
    display: none;
    padding: 6px 12px;
    border: 1px solid #ccc;
    border-top: none;
}

.tabcontent {
    -webkit-animation: fadeEffect 1s;
    animation: fadeEffect 1s; /* Efecto de desvanecer */
}

@-webkit-keyframes fadeEffect {
    from {opacity: 0;}
    to {opacity: 1;}
}

@keyframes fadeEffect {
    from {opacity: 0;}
    to {opacity: 1;}
}

/*boton validar*/
.boton {
    padding: 15px 32px;
    text-align: center;
    text-decoration: none;
    display: inline-block;
    font-size: 16px;
}
.boton {border-radius: 8px;}

.boton {
    background-color: white;
    color: black;
    border: 2px solid #555555;
}

.boton:hover {
    background-color: #555555;
    color: white;
}

</style>

<!--pestañas-->
<ul class="tab">
  <font face="verdana"><li><a href="javascript:void(0)" class="tablinks" onclick="pestaña(event, 'Progra')" id="defaultOpen">Programa</a></li>
  <li><a href="javascript:void(0)" class="tablinks" onclick="pestaña(event, 'Instrucciones')">Instrucciones</a></li></font>


</ul>
<!--botones, cajas de texto, etc, del programa principal-->
<div id="Progra" class="tabcontent">
 <font face="verdana"> <h3><center>Desigualdades</center></h3></font>
  <form action="igualdades.php" method="post">
<div class="exp1">
<p><font face="verdana">Expresión 1</p></font>
</div>
<div class="exp2">
 <p><font face="verdana">Expresión 2</p></font>
</div>

<center><br><br> <input type="text" name="exp1">
<select name="i">
<option value="0"> </option>
<option value="1">></option>
<option value="2"><</option>
</select>
 <input type="text" name="exp2"<br></center>
<br><center><font face="verdana"><input class="boton" type="submit" value="Validar"></font></center>
</form>

<?php
/*
Autor: Jesús Arturo Araiza Grijalva
Descripción: Es un programa que checa igualdades entre dos expresiones, pero lo complicado es que el usuario ingresa los operadores en la caja de texto.
Fecha: 30/Nov/16
Grupo: 1CV1
*/ 
$i=$_REQUEST["i"];
$j; //para los for
$exp1=($_REQUEST["exp1"]);
$exp2=($_REQUEST["exp2"]);
$array1=str_split($exp1); //convierte el string en un array
$res;
$fov=array("falso","verdadero");
$jfov=0; //para imprimir falso o verdadero dependiendo del caso
$sl1=strlen($exp1);
$temp;

/*JERARQUIZACION Y ALGORITMO PRINCIPAL */
	
//Potencias.
for($j=1;$sl1>2;$sl1=$sl1-2)
{
	if($array1[$j]=='^')
	{
		$temp=pow($array1[$j-1],$array1[$j+1]);
		$array1[$j-1]=$temp;
		unset($array1[$j], $array1[$j+1]);
		$array1=array_values($array1);
	}
	else{
	$j=$j+2;
	}
}
//Multiplicación.
$sl1=strlen($exp1);
for($j=1;$sl1>2;$sl1=$sl1-2)

{
	if($array1[$j]=='*')
	{
		$temp=($array1[$j-1]*$array1[$j+1]);
		$array1[$j-1]=$temp;
		unset($array1[$j], $array1[$j+1]);
		$array1=array_values($array1);
	}
	else{
	$j=$j+2;
	}
}
//División.
$sl1=strlen($exp1);
for($j=1;$sl1>2;$sl1=$sl1-2)

{	
	if($array1[$j]=='/')
	{
		if($array1[$j+1]=="0")
		{
			echo"No se puede dividir entre 0";
			$zero=1;
		}
		else
		{
		$temp=($array1[$j-1]/$array1[$j+1]);
		$array1[$j-1]=$temp;
		unset($array1[$j], $array1[$j+1]);
		$array1=array_values($array1);
		}
		
	}
	else{
	$j=$j+2;
	}
}

//Resta.
$sl1=strlen($exp1);
for($j=1;$sl1>2;$sl1=$sl1-2)

{
	if($array1[$j-2]=='-')
	{
		$temp=(-1*$array1[$j-1]-$array1[$j+1]);

		$array1[$j-1]=$temp;
		unset($array1[$j], $array1[$j+1]);
		$array1=array_values($array1);
	}
	if($array1[$j]=='-')
	{
		$temp=($array1[$j-1]-$array1[$j+1]);
		$array1[$j-1]=$temp;
		unset($array1[$j], $array1[$j+1]);
		$array1=array_values($array1);
	}
	else{
	$j=$j+2;
	}
}

//Suma.
$sl1=strlen($exp1);
for($j=1;$sl1>2;$sl1=$sl1-2)

{
	if($array1[$j]=='+')
	{
		$temp=($array1[$j-1]+$array1[$j+1]);
		$array1[$j-1]=$temp;
		unset($array1[$j], $array1[$j+1]);
		$array1=array_values($array1);
	}
	else{
	$j=$j+2;
	}
}



switch($i){
	case 0: //si el usuario elije el espacio invalido

	
echo'<div class="alert">
  <span class="closebtn">&times;</span> 
  <center><font face="verdana">Porfavor introduzca una igualdad.</font></center>
	</div>';
 

	break;
	
	case 1: //si el usuario elije >
	
	if($array1[0]>$exp2)
	{
	$jfov=1;
	}

	else
	{
	$jfov=0;
	}
	echo "<br><center><h1>Resultado: $array1[0] > $exp2 es $fov[$jfov].</h1></center>"; 
	break;
	
	case 2: //si el usuario elije <
	if($array1[0]<$exp2)
	{
	$jfov=1;
	}
	else
	{
	$jfov=0;
	}
	echo "<br><h1><center>Resultado: $array1[0] < $exp2 es $fov[$jfov].</h1></center>";
	break;
	
}
?>
</div>

<!-- Contenido pestaña instrucciones -->
<div id="Instrucciones" class="tabcontent">
  <font size="7" face="verdana"><b><center>Instrucciones</center></b></font>
  <ul>
  <font face="verdana"><p>Este programa resuelve desigualdades matemáticas.</p>
  <li>La expresión 1 es capaz de resolver ecuaciones matemáticas simples. Para que el programa funcione sin problemas, es necesario que solo introduzca números de un solo dígito en la expresión 1.</li>
  <li>La expresión 2 sirve para introducir un valor a comparar. En este apartado se pueden meter valores de más de un dígito</li>
  <br>
  <p>Para hacer operaciones los siguientes símbolos son necesarios:</p>
  <li>Potencia: <b>^</b></li>
  <li>Multiplicación: <b>*</b></li>
  <li>División: <b>/</b></li>
  <li>Suma: <b>+</b></li>
  <li>Resta: <b>-</b></li></font>
</ul>
<div class="firma">
<p>Hecho por: Jesús Arturo Araiza Grijalva. (ʘ_ʘ)</p>
</div>
</div>




<title>Igualdades</title>


		<!--Javascript-->
<script>

function pestaña(evt, cityName) {
    // variables
    var i, tabcontent, tablinks;

    // Esconder los elementos dentro de la clase tab
    tabcontent = document.getElementsByClassName("tabcontent");
    for (i = 0; i < tabcontent.length; i++) {
        tabcontent[i].style.display = "none";
    }

    // agarrar todos los elementos de la clase="tablinks" y eliminar la clase "active"
    tablinks = document.getElementsByClassName("tablinks");
    for (i = 0; i < tablinks.length; i++) {
        tablinks[i].className = tablinks[i].className.replace(" active", "");
    }

    // Muestra la pestaña actual y añade una clase "activo" al link que abrio la pestaña
    document.getElementById(cityName).style.display = "block";
    evt.currentTarget.className += " active";
}

//Para tener una tab por default
document.getElementById("defaultOpen").click();

var close = document.getElementsByClassName("closebtn");
var i;
for (i = 0; i < close.length; i++) {
    close[i].onclick = function(){
        var div = this.parentElement;
        div.style.opacity = "0";
        setTimeout(function(){ div.style.display = "none"; }, 600);
    }
}
</script>

</body>
</html>