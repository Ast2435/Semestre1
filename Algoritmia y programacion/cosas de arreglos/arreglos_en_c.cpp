#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//las funciones para los arreglos dinamicos estaran dentro de la libreria stdlib.h
int i;

void desplegar(int*arreglo,int size)
{
	for(i=0;i<size;i++)
	{
		printf("%d ",arreglo[i]);
	}
	printf("\n");
}

void insertar(int*arreglo,int size)
{
	for(i=0;i<size;i++)
	{
		arreglo[i]=rand()%100;
	}
}
int main()
{
	int *A,*B;
	int lon_a,lon_b,bandera=1,opc;
	//el programa generara numeros aleatorios dentro del arreglo dinamico
	srand(time(NULL));
	
	printf("asigne el tama%co del arreglo A\n",164);
	scanf("%d",&lon_a);
	A=(int*)malloc(sizeof(int)*lon_a);
	//la funcion malloc solicita el espacio de memoria pero no lo limpia, por lo que al desplegar lo mas probable es que contenga basura
	printf("asigne el tama%co del arreglo B\n",164);
	scanf("%d",&lon_b);
	B=(int*)calloc(lon_b,sizeof(int));
	//calloc solicita memoria y ademas limpia los espacio de memoria dejandolo en valores por defecto
	printf("arreglos en c\n");
	printf("menu:\n\n");
	printf("1)desplegar arreglo A\n");
	printf("2)meter numeros aleatorios en el arreglo A\n");
	printf("3)cambiar el tama%co de A\n",164);
	printf("4)desplegar arreglo B\n");
	printf("5)meter numeros aleatorios en el arreglo B\n");
	printf("6)cambiar el tama%co de B\n\n",164);
	
	do
	{
		printf("ingrese el numero de la accion\n");
		scanf("%d",&opc);
		printf("\n");
		switch(opc)
		{
			case 1:
				desplegar(A,lon_a);//llama a la funcion desplegar
				break;
			case 2:
				insertar(A,lon_a);//llama a la funcion insertar
				break;
			case 3:
				printf("ingrese el nuevo tamaño de A\n");
				scanf("%d",&lon_a);
				A=(int*)realloc(A,lon_a*sizeof(int));
				//realloc solicita 2 parametros, el primero es el apuntador y el segundo es el espacio de memoria a solicitar
				//realloc funciona como malloc, si se aumenta el tamaño del arreglo los nuevos espacion tendran basura
				break;
			case 4:
				desplegar(B,lon_b);
				break;
			case 5:
				insertar(B,lon_b);
				break;
			case 6:
				printf("ingrese el nuevo tamaño de B\n");
				scanf("%d",&lon_b);
				B=(int*)realloc(B,lon_b*sizeof(int));
				break;
			case 7:
				bandera=0;
				break;				
		}
	}while(bandera==1);
	
	free(A);
	free(B);
}
