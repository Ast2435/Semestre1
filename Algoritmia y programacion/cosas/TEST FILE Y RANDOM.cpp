#include<stdio.h>
#include<stdlib.h>
#include<time.h>


FILE *patito;
int main ()
{
srand(time(NULL));

	int a,i;
	patito=fopen("numeros.cvs","w");
	if(patito!=NULL)
	{
		for(i=0;i<20;i++)
		{
			a=rand()%100+1;
			fprintf(patito,"%d;",a);		
		}
		
	}
	else
	{
		printf("ERROR. El archivo no ha sido creado.");
	}
	
	
	fclose(patito);	
return 1;
}
