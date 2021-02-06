#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	char string[20], texto1[30], texto2[30], sib[2];
	int ta,i,x;
	sib[0]='%';
	sib[1]='s';
	
	printf("con la instrucion %c%c se puede desplegar el arreglo de char de forma consecutiva\n",sib[0],sib[1]);
	
	printf("escriba su nombre [max 20 letras]\n");
	scanf("%s",string);
	fflush(stdin);
	printf("\ntexto: %s\n",string);
	
	printf("\nel scanf no puede guardar oraciones con espacios\n");
	printf("por lo que solo guarda la primer palabra\n");
	
	printf("\nescriba una oracion [max 30 letras, incluyendo espacios]\n");
	scanf("%s",&texto1);
	fflush(stdin);
	
	printf("\ntexto: %s\n",texto1);
	printf("\npara esto tenemos gets(); que guarda el texto de entrada\n",sib[0],sib[1]);
	printf("hasta que haya un salto de linea\n");
	
	printf("\nescriba una oracion [max 30 letras, incluyendo espacios]\n");
	gets(texto2);
	printf("\ntexto: %s\n",texto2);
	return 1;
}

