/*
	Name: Programa sistema de ecuaciones
	Copyright: Registrado en 2009 por flavio
	Author: Jesús Arturo Araiza Grijalva && Delgadillo Barajas Oscar Alejandro.
	Date: 07/10/16 18:21
	Description: Programa que resuelve ecuaciones lineales, no está terminado ya que tiene un pequeño problema con la impresión del resultado. (pero sí sirve) 
*/


#include<stdio.h>
//i=filas
//j=columnas

//funcion guarda valores
void valores(int sq)
{
int i,j,k,x,cont=0,cont2=1,temp;
int A[sq][sq],B[sq]; 
for(k=0;k<sq;k++)
{
	for(i=0;i<sq;i++)
	{
		printf("\nDame un valor de X%d posicion %d\n",cont2,i);
		scanf("%d",&x);
		A[i][cont]=x;
	}
	for(i=0;i<sq;i++)
	{
		
		//imprime el arreglo
		for(i=0;i<sq;i++)
		{
			printf("A[%d][%d]=%d\t",i,cont,A[i][cont]); 
		}
cont++;
cont2++;
}
}
}

int main()
{
	int i,j; //para los for
	int x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,k; //k es la constante
	int sq; //determinar el tamaño de la matriz

	printf("Porfavor introduzca el tamaño de su matriz (Menor o igual a 10 y mayor que 1)\n");
	scanf("%d",&sq); 
	while(sq>10 || sq<=1)
	{
	printf("Valor invalido, introduzca un numero menor o igual a 10 y mayor que 1\n");
	scanf("%d",&sq); 
	}
	int A[sq][sq], B[sq]; 
	//limpia el programa
	for(i=0;i<sq;i++)
	{
    	for(j=0;j<sq;j++)
    	{  
       		 A[i][j]=0;
    	}
	}
//determina el tamaño de la matriz
valores(sq);

//valor de la constante
for(i=0;i<sq;i++)
	{
		printf("\n\nDame un valor de la constante K%d\n",i);
		scanf("%d",&k);
		B[i]=k;
	}
for(i=0;i<sq;i++)
{
	for(j=0;j<sq;j++)
	{
	A[i][sq+1]=B[i];
	}
	for(i=0;i<sq;i++)
		{
			printf("A[%d][%d]=%d\t",i,sq+1,A[i][sq+1]); 
		}
}
//imprime todo (algo anda mal)
for(i=0;i<sq;i++)
	{
		printf("\n");
		for(j=0;j<sq;j++)
		{
		printf("%d\t",A[i][j]); //imprime el arreglo
		}
	}

return 1;		
}
