//Jes√∫s Arturo Araiza Grijalva
//1CV1
//Test de primalidad usando la libreria gmp para poder usar su funci√≥n "mpz_probab_prime_p" que usa el algoritmo de Miller-Rabin,
 //asi como prueba de divisi√≥n en numeros peque√±os para comprobar si un n√∫mero es primo o no.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<gmp.h>
//FunciÛn recursiva para algoritmo euclideano extendido
long long int xmcd(long long int a, long long int b, long long int &x, long long int &y)
 {
    if(b == 0)
	 {
       x = 1;
       y = 0;
       return a;
    }

    long long int x1, y1, mcd = xmcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return mcd;
}
//Funcion para calcular factores primos
void Factor_primo(long long int i)
{
//While para cuando i es par
int cont1=0;
while (i%2==0)
{
i=i/2;
cont1++;
}
if (cont1!=0)
printf("2^%d ",cont1);
//For para cuando i ya no es par
int cont2=0;
for (long long int j=3;j<=sqrt(i);j=j+1)
{
//Mientras j divide a i, imprime j y divide a i
cont2=0;
while (i%j==0)
{
i=i/j;
cont2++;
}
//Condicion para imprimir solo los factores que esten elevados a mas que 0
if (cont2!=0)
printf("%lld^%d ",j,cont2);
}
//Para cuando i es un n˙mero primo mayor que 2
if (i>2)
printf ("%lld ",i);
}

int main()
{
int i; //Para el switch
do
{
printf("\t\t\t\t\t1-Test de primalidad.\n");
printf("\t\t\t\t\t2-Algoritmo de divisi\242n.\n");
printf("\t\t\t\t\t3-Algoritmo Euclideano extendido con igualdad de Bezout.\n");
printf("\t\t\t\t\t4-Algoritmo de factores primos.\n");
printf("\t\t\t\t\t5-Algoritmo para calcular el MCM.\n");
printf("\t\t\t\t\t6-Informaci\242n del programa.\n");
printf("\t\t\t\t\t7-Salir del programa.\n");
printf("---------------------------------------------------------------------------------------\n"); 
printf("\250Qu\202 operaci\242n desea realizar? ");
scanf("%d",&i);
switch(i)
{
case(1): //caso uno: test de primalidad
{
	mpz_t n;
	mpz_init(n);
	int i;
	printf("Ingrese un n\243mero para comprobar su primalidad\n"); //Espero que nadie le ponga uno par...
	gmp_scanf("%Zd",&n);

//Algoritmo de Miller-Rabin, mientras mas iteraciones haga mas seguro es el resultado.
i=mpz_probab_prime_p (n,20);//n es el numero que comprobaremos y 20 son las iteraciones.   
printf("---------------------------------------------------------------------------------------\n");  
if (i==0)
	gmp_printf("%Zd es compuesto\n",n); 
if (i==1)
	gmp_printf("%Zd es muy probablemente primo\n",n);
if (i==2)
	gmp_printf("%Zd es definitivamente primo\n",n);
printf("---------------------------------------------------------------------------------------\n");  
}
break;
case(2): //caso dos: algoritmo de division
{
long long int a,b,q=0,r=0;
printf("Introduzca el valor de A:\n");
scanf("%lld",&a);
printf("Introduzca el valor de B (Mayor que 1):\n");
scanf("%lld",&b);

while(a==0) 
{
printf("El valor de r es 0 y el de q es 0 tales que a=b(0)+(0)\n");
printf("---------------------------------------------------------------------------------------\n"); 
}

while(b<1)
{
printf("El valor de B(%d) no es v\240lido, porfavor ingrese un valor mayor que 1:\n",b);
scanf("%lld",&b);
}

for(a>0; ;q++)
	{
		r=a-(b*q);
		
		if(r<0)
		{
		q=q-1;
		r=a-(b*(q));
		break;
		}
			
	}
for(a<0; ;q--)
	{
		r=a-(b*q);
		
		if(r>0)
		{
		r=a-(b*(q));
		break;
		}
			
	}
printf("El valor de r es %lld y el de q es %lld tales que %lld=%lld(%lld)+(%lld)\n",r,q,a,b,q,r);
printf("---------------------------------------------------------------------------------------\n"); 
}

break;

case(3): //Caso 3: Algoritmo euclideano extendido con igualdad de Bezout.
{
long long int a, b, x, y, mcd, temp;
printf("Introduzca el valor (positivo) de a:\n");
scanf("%lld",&a);
while (a<0)
{
printf("El valor de a(%lld) no es v\240lido, porfavor ingrese un valor postivo para a:\n",a);
scanf("%lld",&a);
}
printf("Introduzca el valor (positivo) de b:\n");
scanf("%lld",&b);
while (b<0)
{
printf("El valor de b(%lld) no es v\240lido, porfavor ingrese un valor postivo para b:\n",b);
scanf("%lld",&b);
}

   if(a < b)
   {
   	temp=a;
   	a=b;
   	b=temp;
   }

mcd = xmcd(a, b, x, y);
	printf("el MCD es: %lld, x=%lld y y=%lld que es igual a la forma mcd(%lld,%lld)=%lld(%lld)+%lld(%lld)\n",mcd,x,y,a,b,a,x,b,y);
	printf("---------------------------------------------------------------------------------------\n"); 
	
}
break;

case(4): //Caso 4: Algoritmo que encuentra factores primos de un n˙mero.
{
long long int i;
printf("Ingrese un n\243mero positivo para calcular sus factores primos:\n");
scanf("%d",&i);
while(i<0)
{
printf("El n\243mero que ingres\242 no es positivo, porfavor ingrese un n\243mero positivo:\n");
scanf("%d",&i);	
}
Factor_primo(i);
printf("---------------------------------------------------------------------------------------\n"); 
}
break;

case(5): //caso 5: Minimo comun multiplicador
{
long long int a, b, x, y, mcd, mcm, temp;
printf("Introduzca el valor (positivo) de a:\n");
scanf("%lld",&a);
while (a<=0)
{
printf("El valor de a(%lld) no es v\240lido, porfavor ingrese un valor postivo para a:\n",a);
scanf("%lld",&a);
}
printf("Introduzca el valor (positivo) de b:\n");
scanf("%lld",&b);
while (b<=0)
{
printf("El valor de b(%lld) no es v\240lido, porfavor ingrese un valor postivo para b:\n",b);
scanf("%lld",&b);
}

   if(a < b)
   {
   	temp=a;
   	a=b;
   	b=temp;
   }

mcd = xmcd(a, b, x, y);
//linea que calcula el mcm a partir del mcd
mcm=(a*b)/mcd;
printf("El mcd entre %lld y %lld es %lld\n",a,b,mcm);
printf("---------------------------------------------------------------------------------------\n"); 
}
break;

case(6): //Caso 5: InformaciÛn
{
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t\tAcerca del programa\n\n\n");
	printf("Este programa fue creado por Jes\243s Arturo Araiza Grijalva del grupo 1CV1 para la asignatura de Matem\240ticas Discretas\n\n\n");
	printf("1-El primer programa es un test de primalidad que nos puede decir si un n\243mero es primo o no, este programa puede llegar hasta 10,000 digitos.\n");
	printf("2-El segundo programa es el algoritmo de la divisi\242n que nos puede dar el residuo y el cociente entre dos n\243meros.\n");
	printf("3-El tercer programa es el algoritmo de Euclides extendido, que nos da el M\240ximo Com\243n Divisor entre dos n\243meros y nos lo comprueba con la igualdad de Bezout. \n"); 
	printf("4-El cuarto programa nos da los factores primos de un n\243mero, que son los n\243meros primos en los que este n\243mero se descompone.\n");
	printf("4-El quinto programa nos proporciona el Minimo Com\243n Multiplicador entre dos n\243meros. \n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
}
break;


default:
	exit(0);
} //Llave del switch
}
while(i<7);
return 1;
}



