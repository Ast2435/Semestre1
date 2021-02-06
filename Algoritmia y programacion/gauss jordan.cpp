/*
	Name: Gauss Jordan
	Copyright: Código Libre
	Author: Jesús Arturo Araiza Grijalva.
	Date: 11-11-16 12:26
	Description: Programa que resuelve ecuaciones con números aleatorios por el método de Gauss jordan.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main( )
{
	FILE *perrito;
	srand(time(NULL));
	int i,j,k,n,p;

    float d,h[10001];
    printf("\nIngrese el tamaño de la matriz: ");
    scanf("%d",&n);
    
    //float (*A)[n] = malloc(sizeof(float[n][n]));
    
    
 	float **A;
	A = (float**)calloc(10001,sizeof(float*));
	for(int i = 0; i < 10001; i++)
    A[i] = (float*)calloc(10001,sizeof(float));
	
    //Introduce valores aleatorios.
    int rando;
     for(i=1;i<=n;i++)
    {
        for(j=1;j<=(n+1);j++)
        {
   		rando=rand()%999;
   		rando=rando-250;
            A[i][j]=rando;
        }
    }
    
    //Guarda los valores en un archivo .CVS
    perrito=fopen("ecuaciones.csv","w");
    if(perrito==NULL)
    {
    	printf("Hubo un error al crear el archivo\n");
	}
	else
	{
    for(i=1;i<n;i++)
	 {
		for(j=1;j<n+1;j++)
		 {
    		fprintf(perrito,"%.3f;",A[i][j]);
		}
		fprintf(perrito,"\n");
	}
	 fclose(perrito);
	}
	
   /* //IMPRIME LAS MATRICES SOLO PARA PRUEBAS
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n+1; j++)
        {
            printf(" A[%d][%d]=%.3f\n", i,j,A[i][j]);
        }
    }*/
    
    
    //Encuentra la diagonal
    for(j=1; j<=n; j++)
    {
        for(i=1; i<=n; i++)
        {
            if(i!=j)
            {
                d=A[i][j]/A[j][j];
                for(k=1; k<=n+1; k++)
                {
                    A[i][k]=A[i][k]-d*A[j][k];
                }
            }
        }
    }
 
   // printf("%d",A[0][0]);  /*<--- era solo para pruebas*/
    printf("\nLas soluciones son:\n");
    for(i=1; i<=n; i++)
    {
        h[i]=A[i][n+1]/A[i][i];
        printf("\n x%d=%.3f\n",i,h[i]);
    }
    FILE *gatito;
    gatito=fopen("soluciones.csv","w");
    if(gatito==NULL)
    {
    	printf("Hubo un error al crear el archivo\n");
	}
	else
	{
    for(i=1;i<n;i++)
	 {
    		fprintf(gatito,"x%d=%.3f;",i,A[i]);
	}
	 fclose(gatito);
	}
    
//No se debe de olvidar nunca liberar el espacio, o tona te reprueba.
free (A);
	
return 1;
}
