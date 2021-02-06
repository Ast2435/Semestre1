//Jesús Arturo Araiza Grijalva.
//Marco Antonio Maximo Galvan.
//1CV1
//23/09/2016
//programa de funciones y arreglos

#include<stdio.h>
#include<time.h>
#include <stdlib.h>

void burbuja(int a[], int);
void presentar_menu(void);
void desordena(int a[], int);
int main(void)
{
	int opc;
	int estado=0;
	do
	{
presentar_menu();

scanf("%d",&opc);
switch(opc)
{
case 1:
srand(time(NULL));
int rnum[20];
int k;

for(k=0;k<sizeof (rnum) / sizeof (int);k++)
{
	
	rnum[k]=0;
	}


int n,i;
printf("Ingrese cuantos números aleatorios desea (hasta 20) \n");
scanf("%d", &n);

if(n<=20)
{

for(i=0;i<n;i++)
{
	rnum[i] = rand() %100+1;
	
}

estado=1;

}else{
	
	printf("Ingrese un numero menor o igual a 20\n");
}

break;

case 2:

if(estado==1)
{

burbuja(rnum, sizeof (rnum) / sizeof (int));
}else{
	printf("--------------------------------\nGenere numeros primero\n");
	}
break;

case 3:

printf("---------------------------------------------\n");

if(estado==1)
{
for(i=0;i<sizeof (rnum) / sizeof (int);i++)
{
	
	if(rnum[i]!=0){
	printf("%d\t",rnum[i]);
}
	}
	printf("\n");
}
else
{
	printf("--------------------------------\nGenere numeros primero\n");
}

break;

case 4:

if(estado==1)
{

desordena(rnum, sizeof (rnum) / sizeof (int));

}
else
{
	printf("--------------------------------\nGenere numeros primero\n");
}

break;
}
}
while(opc!=5);




return 1;
}

/*burbuja(a, sizeof (a) / sizeof (int));*/

 void burbuja(int a[],int tam)
 {
	 int i, k, aux;
	 
	 printf("tamano %d\n",tam);
	 
	 for(i=0;i<tam;i++){
		 
		 		 for(k=0;k<tam;k++)
		 		 {
			 
			 if(a[i]<a[k])
			 {
				 
				 aux=a[i];
				 a[i]=a[k];
				 a[k]=aux;
				 
				 }
			 
			 }

		 }
	 }


 void desordena(int a[],int tam)
 {
	 int i, k, aux;
	 
	 for(i=0;i<tam;i++)
	 {
		 
		 		 for(k=0;k<tam;k++)
		 		 {
					 
					 if((i/2)*2==i)
					 {
				 if(a[i]<a[k])
				 {
				 aux=a[i];
				 a[i]=a[k];
				 a[k]=aux;
						 }
						 }
						 else 
						 {
							 
                 if(a[i]>a[k])
                 {
				 aux=a[i];
				 a[i]=a[k];
				 a[k]=aux;
						 }  
							 
							 }
			 

				 
				 }
			 
			 }

		 } 
	 
void presentar_menu(void)
{

      printf("-------------------------------------------------\n");
      printf("MENU\n");
      printf("SELECCIONE ALGUNA DE LAS SIGUIENTES OPCIONES:\n");
      printf("-------------------------------------------------\n\n");
      printf("1) GENERA N ALEATORIOS\n");
      printf("2) ORDENE POR MÉTODO DE BURBUJA\n");
      printf("3) MUESTRE\n");
      printf("4) DESORDENA\n");
      printf("5) SALIR\n");
	}



