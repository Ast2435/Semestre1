#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int i, j;
//funcion para desplegar matrices, se para el apuntador como parametro
void desplegar(int **matriz,int f, int c)
{
	for (i=0; i<f; i++) 
	{
		for (j=0; j<c; j++) 
		{
			printf("%d\t", matriz[i][j]); 
		}
		printf("\n"); 
	}
	printf("\n");
}
void insertar(int **matriz,int f, int c)
{
	for (i=0; i<f; i++) 
	{
		for (j=0; j<c; j++)
		{
			matriz[i][j]=rand()%500; 
		}	
	}
}
int main(void) 
{
	int bandera=1, opc, nf, nc, a_filas, a_columnas, b_filas, b_columnas;
	int **A,**B;

	srand(time(NULL));
	
	//asignamos el tamaño para la matriz A
	printf("teclee el numero de filas para A\n");
	scanf("%d",&a_filas);
	printf("teclee el numero de columnas para A\n");
	scanf("%d",&a_columnas);
	//aqui reservamos la memoria con la funcion malloc, primero debemos hacer la inicializacion de las filas
	A = (int **)malloc(a_filas*sizeof(int*));
	for (i=0;i<a_filas;i++)
	{
		//y despues de le asigna a cada fila los espacios de las columnas
		A[i] = (int*)malloc(a_columnas*sizeof(int)); 
	}
	
	//asignamos el tamaño para la matriz B
	printf("teclee el numero de filas para B\n");
	scanf("%d",&b_filas);
	printf("teclee el numero de columnas para B\n");
	scanf("%d",&b_columnas);
	//aqui declaramos la memoria con la funcion calloc, del mismo modo va primero las filas y luego las columnas
	B=(int**)calloc(b_filas,sizeof(int*));
	for(i=0;i<b_filas;i++)
	{
		B[i]=(int*)calloc(b_columnas,sizeof(int));
	}
	printf("\n"); 
	printf("matrices en c\n");
	printf("menu:\n\n");
	printf("1)desplegar la matriz A\n");
	printf("2)meter numeros aleatorios en la matriz A\n");
	printf("3)cambiar el tama%co de A\n",164);
	printf("4)desplegar la matriz B\n");
	printf("5)meter numeros aleatorios en la matriz B\n");
	printf("6)cambiar el tama%co de B\n\n",164);
	
	do
	{
		printf("ingrese el numero de la accion\n");
		scanf("%d",&opc);
		printf("\n");
		switch(opc)
		{
			case 1:
				desplegar(A,a_filas,a_columnas);//llama a la funcion desplegar
				break;
			case 2:
				insertar(A,a_filas,a_columnas);//llama a la funcion insertar
				break;
			case 3:
				printf("teclee el nuevo numero de filas\n");
				scanf("%d",&nf);
				printf("teclee el nuevo numero de columnas\n");
				scanf("%d",&nc);
				//para redimencionar la matriz se divide en 2 casos, cuando agregas filas o cuando quitas filas
				A=(int **)realloc(A, sizeof(int*)*nf);
				if(nf>a_filas)//agregas filas, se inicializa con calloc las nuevas columnas de esa fila
				{
					for(i=(nf-a_filas);i>0;i--)
					{
						A[nf-i]=(int*)calloc(nc,sizeof(int));//agrega las columnas en las filas nuevas
					}
				}
				else//aqui se quitan las filas y se pueden agregar o quitar columnas
				{
					for(i=0;i<nf;i++)
					{
						A[i]=(int*)realloc(A[i],sizeof(int)*nc);
					}
				}
				a_filas=nf;
				a_columnas=nc;
				break;
			case 4:
				desplegar(B,b_filas,b_columnas);
				break;
			case 5:
				insertar(B,b_filas,b_columnas);
				break;
			case 6:
				printf("teclee el nuevo numero de filas\n");
				scanf("%d",&nf);
				printf("teclee el nuevo numero de columnas\n");
				scanf("%d",&nc);
				//para redimencionar la matriz se divide en 2 casos, cuando agregas filas o cuando quitas filas
				B=(int **)realloc(B, sizeof(int*)*nf);
				if(nf>b_filas)//agregas filas, se inicializa con calloc las nuevas columnas de esa fila
				{
					for(i=(nf-b_filas);i>0;i--)
					{
						B[nf-i]=(int*)calloc(nc,sizeof(int));//agrega las columnas en las filas nuevas
					}
				}
				else//aqui se quitan las filas y se pueden agregar o quitar columnas
				{
					for(i=0;i<nf;i++)
					{
						B[i]=(int*)realloc(B[i],sizeof(int)*nc);
					}
				}
				b_filas=nf;
				b_columnas=nc;
				break;
			case 7:
				bandera=0;
				break;				
		}
	}while(bandera==1);
	
	free(A);
	free(B);
	return 1; 
} 
