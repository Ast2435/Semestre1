//Jesús Arturo Araiza Grijalva
//1CV1
//Test de primalidad usando la libreria gmp para poder usar su función "mpz_probab_prime_p" que usa el algoritmo de Miller-Rabin, asi como prueba de división en numeros pequeños para comprobar si un número es primo o no. Más información en el video adjunto.

#include<stdio.h>
#include<gmp.h>

int main()
{
	int q=1;
do
{
	mpz_t n;
	mpz_init(n);
	int i;
	printf("Ingrese un n\243mero para comprobar su primalidad\n"); //Espero que nadie le ponga uno par...
	gmp_scanf("%Zd",&n);

//Algoritmo de Miller-Rabin, mientras mas iteraciones haga mas seguro es el resultado.
i=mpz_probab_prime_p (n,20);//numero de iteraciones   
printf("-------------------------------------------------------------------------\n"); 
if (i==0)
	gmp_printf("%Zd es compuesto\n",n); 
if (i==1)
	gmp_printf("%Zd probablemente es primo\n",n);
if (i==2)
	gmp_printf("%Zd es definitivamente primo\n",n);
printf("-------------------------------------------------------------------------\n"); 
}
while (q=1);
return 1;
}
