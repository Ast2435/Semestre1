 <!--Autor: Jesús Arturo Araiza Grijalva
Descripción: Peint es un programa que utiliza canvas de HTML5 para dibujar
Fecha: 30/Nov/16
Grupo: 1CV1-->

 <html>
    <body onload="init()">
  <title>Peint</title>
  
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

/*cursor de cruz*/
 canvas {
    cursor: crosshair;
    border: 1px solid #000000;
	}
	
	/* estilo pestañas */
ul.tab {
    list-style-type: none;
    margin: 0;
    padding: 0;
    overflow: hidden;
    border: 1px solid #ccc;
    background-color: #f1f1f1;
}

/* pestañas de lado */
ul.tab li {float: left;}

/* estilo al link de las pestañas */
ul.tab li a {
    display: inline-block;
    color: black;
    text-align: center;
    padding: 14px 16px;
    text-decoration: none;
    transition: 0.3s;
    font-size: 17px;
}

/* cambiar el color de fondo si el mouse pasa */
ul.tab li a:hover {background-color: #ddd;}

/* crear y activar clase activa de tabs */
ul.tab li a:focus, .active {background-color: #ccc;}

/* Estilo del contenido de tabs */
.tabcontent {
    display: none;
    padding: 6px 12px;
    border-top: none;
}

.tabcontent {
    -webkit-animation: fadeEffect 1s;
    animation: fadeEffect 1s; /* efecto de desvanecimiento */
}

@-webkit-keyframes fadeEffect {
    from {opacity: 0;}
    to {opacity: 1;}
}

@keyframes fadeEffect {
    from {opacity: 0;}
    to {opacity: 1;}
}

</style>

	
    <script type="text/javascript">
	

	
    var canvas, ctx, flag = false, 
        prevX = 0,
        currX = 0,
        prevY = 0,
        currY = 0,
        dot_flag = false;
    var x = "black", //variable color cursor
        y = 2; //variable tamaño cursor
    
	//Inicia el canvas.
    function init() { 
        canvas = document.getElementById('can');
        ctx = canvas.getContext("2d");
        w = canvas.width;
        h = canvas.height;
		ctx.fillStyle = "white";
		ctx.fillRect(0, 0, canvas.width, canvas.height);
		
		
		
		//lee el input del mouse
        canvas.addEventListener("mousemove", function (e) {
            findxy('move', e)
        }, false);
        canvas.addEventListener("mousedown", function (e) {
            findxy('down', e)
        }, false);
        canvas.addEventListener("mouseup", function (e) {
            findxy('up', e)
        }, false);
        canvas.addEventListener("mouseout", function (e) {
            findxy('out', e)
        }, false);
    }
    
    function color(obj) {
        switch (obj.id) {
            case "green":
                x = "green";
                break;
            case "blue":
                x = "blue";
                break;
            case "red":
                x = "red";
                break;
            case "yellow":
                x = "yellow";
                break;
            case "orange":
                x = "orange";
                break;
            case "black":
                x = "black";
                break;
            case "white":
                x = "white";
                break;
        }
        if (x == "white") y = 14;
		y = 2;
    }
	
    function tamaño(obj) {
		switch(obj.id){
			case "mas":
			temp = y + 2;
			y = temp;
			break;
			case "menos":
			temp = y - 2;
			y = temp;
		}
	}
	
	//Funcion que hace que sirva el dibujo con el mouse
    function draw() {
        ctx.beginPath();
        ctx.moveTo(prevX, prevY);
        ctx.lineTo(currX, currY);
        ctx.strokeStyle = x;
        ctx.lineWidth = y;
        ctx.stroke();
        ctx.closePath();
    }
	

    
    function erase() {
        var m = confirm("¿Esta seguro de que quiere borrar todo?");
        if (m) {
            ctx.clearRect(0, 0, w, h);
            document.getElementById("canvasimg").style.display = "none";
			ctx.fillStyle = "white";
			ctx.fillRect(0, 0, canvas.width, canvas.height);
        }
    }
    
    function save() {
        document.getElementById("canvasimg").style.border = "2px solid";
        var dataURL = canvas.toDataURL();
        document.getElementById("canvasimg").src = dataURL;
        document.getElementById("canvasimg").style.display = "inline";
		
    }
    
	//Funcion que se llama cuando mueves el mouse para encontrar xy
    function findxy(res, e) {
        if (res == 'down') {
            prevX = currX;
            prevY = currY;
            currX = e.clientX - canvas.offsetLeft;
            currY = e.clientY - canvas.offsetTop;
    
            flag = true;
            dot_flag = true;
            if (dot_flag) {
                ctx.beginPath();
                ctx.fillStyle = x;
                ctx.fillRect(currX, currY, 2, 2);
                ctx.closePath();
                dot_flag = false;
            }
        }
        if (res == 'up' || res == "out") {
            flag = false;
        }
        if (res == 'move') {
            if (flag) {
                prevX = currX;
                prevY = currY;
                currX = e.clientX - canvas.offsetLeft;
                currY = e.clientY - canvas.offsetTop;
                draw();
            }
        }
    }
	
	//TABS
function Pestaña(evt, tab) {
    var i, tabcontent, tablinks;
    tabcontent = document.getElementsByClassName("tabcontent");
    for (i = 0; i < tabcontent.length; i++) {
        tabcontent[i].style.display = "none";
    }
    tablinks = document.getElementsByClassName("tablinks");
    for (i = 0; i < tablinks.length; i++) {
        tablinks[i].className = tablinks[i].className.replace(" active", "");
    }
    document.getElementById(tab).style.display = "block";
    evt.currentTarget.className += " active";
}

    </script>
	
	
<font face="verdana">	
<ul class="tab">
  <li><a href="javascript:void(0)" class="tablinks"  onclick="Pestaña(event, 'Peint')" id="defaultOpen">Peint</a></li>
  <li><a href="javascript:void(0)" class="tablinks" onclick="Pestaña(event, 'Instrucciones')">Instrucciones</a></li>
</ul>

<div id="Peint" class="tabcontent">
  <p>
          <canvas id="can" width="400" height="400" style="position:absolute;top:10%;left:10%;border:2px solid;"></canvas>
        <div style="position:absolute;top:12%;left:41%;">Escoja un color</div>
        <div style="position:absolute;top:15%;left:43%;width:10px;height:10px;background:green;" id="green" onclick="color(this)"></div>
        <div style="position:absolute;top:15%;left:44%;width:10px;height:10px;background:blue;" id="blue" onclick="color(this)"></div>
        <div style="position:absolute;top:15%;left:45%;width:10px;height:10px;background:red;" id="red" onclick="color(this)"></div>
        <div style="position:absolute;top:17%;left:43%;width:10px;height:10px;background:yellow;" id="yellow" onclick="color(this)"></div>
        <div style="position:absolute;top:17%;left:44%;width:10px;height:10px;background:orange;" id="orange" onclick="color(this)"></div>
        <div style="position:absolute;top:17%;left:45%;width:10px;height:10px;background:black;" id="black" onclick="color(this)"></div>
        <div style="position:absolute;top:19%;left:42%;">Borrador</div>
        <div style="position:absolute;top:22%;left:43%;width:15px;height:15px;background:white;border:2px solid;" id="white" onclick="color(this)"></div>
		<div style="position:absolute;top:26%;left:40%;">Cambio de tamaño</div>
		<div style="position:absolute;top:29%;left:40%;width:80px;height:19px;background:LightBlue;"id="mas" onclick="tamaño(this)">Aumentar </div>
        <div style="position:absolute;top:29%;left:46%;width:80px;height:19px;background:red;" id="menos" onclick="tamaño(this)">Disminuir</div>
        <img id="canvasimg" style="position:absolute;top:10%;left:52%;" style="display:none;">
        <input type="button" value="Guardar" id="btn" size="30" onclick="save()" style="position:absolute;top:79%;left:20%;">
        <input type="button" value="Borrar todo" id="clr" size="23" onclick="erase()" style="position:absolute;top:79%;left:25%;">
		
  </p>
  <?php

?>
</div>

<div id="Instrucciones" class="tabcontent">
   <font size="7" face="verdana"><b><center>Instrucciones</center></b></font>

  <font face="verdana"><p>Peint es un programa basado en canvas de html5 que sirve para hacer esbozos.</p>
  <p>En el area blanca usted es capaz de hacer su dibujo utilizando su mouse y sosteniendo click cuando quiera hacer una linea.</p>
  <p>El apartado de "escoja un color" sirve para cambiar el color del cursor, los colores disponibles en esta versión son:</p>
  <ul>
  <font color="green"><li>Verde  </li></font>
  <font color="red"><li>Azul </li></font>
  <font color="red"><li>Rojo </li></font>
  <font color="yellow"><li>Amarillo </li></font>
  <font color="orange"><li>Naranja </li></font>
  <font color="black"><li>Negro </li></font>
  </font>
</ul>
  <?php
 echo "<br>El apartado de \"borrador\" cuenta con una caja que convierte su cursos en color blanco, al combinarse con el fondo blanco puede usarse como un borrador.";
 echo "<br>El apartado de \"cambio de tamaño\" cuenta con dos botones para que pueda cambiar el tamaño del cursor a su conveniencia.";
 echo "<br>El boton de \"guardar\" genera una nueva imagen con una URL para que usted pueda guardar su esbozo en la computadora.";
  echo "<br>El boton de \"borrar todo\" destruye su dibujo actual y reestablece el área de dibujo.";
  ?>
 <div class="firma">
<p>Hecho por: Jesús Arturo Araiza Grijalva.</p>
</div>
</div>
</font>

<script>
document.getElementById("defaultOpen").click();
</script>



    </body>
    </html>