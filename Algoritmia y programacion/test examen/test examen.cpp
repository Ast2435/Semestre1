#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL)); 
	long long int i,j,n,k,r,prom,*cad1,*cad2,cont1=0;
	
	printf("Numero de elementos del arreglo:\n");
	scanf("%lld",&n);
	while(n<1)
	{
	printf("El tamaño del arreglo debe ser mayor que 1, porfavor introduzca otro numero:\n");
	scanf("%lld",&n);
	}
	
	cad1=(long long int*)calloc(n,sizeof(long long int*)); //funcion calloc
	cad2=(long long int*)calloc(n,sizeof(long long int*)); //funcion calloc
	while(cad1==NULL) //si el número introducido por el usuario es muy grande, pasa esto.
	{
		printf("Valor invalido, porfavor ingrese un valor mas pequeño:\n");
		scanf("%d",&n);
		cad1=(long long int*)calloc(n,sizeof(long long int*));
	}
	for(j=0;j<n;j++) //Le da un valor aleatorio a toda mi cadena 1
	{
		cad1[j]=rand()%100+1;
	}
	/*for(i=0;i<n;i++) //imprime mi cadena 1
	{
			printf("%lld\t",cad1[i]); 
		}*/
		
		
//Aqui empieza la parte 2 del programa donde creo la segunda cadena y hago las colisiones.
	
	for(k=0;k<100;k++)
	{
		for(i=0;i<n;i++)
		{
			r=rand()%n;
		if (cad2[r]!=0)
		{
		cont1++;
		
		}
		cad2[r]=cad1[i];
		
		}
		
		free (cad2);
		cad2=(long long int*)calloc(n,sizeof(long long int*));
	}
		
	
	printf("\n\nEl promedio de número de colisiones registradas es: %lld",cont1/100);
	
	free (cad1);
	free (cad2);
return 1;	
}
