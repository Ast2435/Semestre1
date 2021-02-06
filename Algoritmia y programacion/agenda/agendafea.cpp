#include<stdio.h>
#include<stdlib.h>
#include <string.h> 

long long int PE;
char nombre[60];
char grupo[5];
int calif;

FILE *agenda;

void ingresar_datos(void);



int main(void)
{
	
ingresar_datos();


return 1;
}

void ingresar_datos(void)
{
	char *agenda;
	int i,n=2;
	agenda=(char*)calloc(3,sizeof(char*));
	printf("Ingrese boleta\n");
	fflush(stdin);
	scanf("%lld",&PE);
	printf("Ingrese nombre\n");
	fflush(stdin);
	gets(agenda);
	printf("Ingrese grupo\n");
	fflush(stdin);
	gets(agenda);
	printf("Ingrese calificacion\n");
	fflush(stdin);
	scanf("%d",&calif);
	sprintf(agenda,"%lld\t %c\t %c\t %d",PE,nombre,grupo,calif);
	puts(agenda);
	n++;
	
}



