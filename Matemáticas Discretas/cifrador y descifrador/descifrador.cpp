   #include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
void ord(char abecedario[])
{
	
	int i,j;
	for(i=0,j=32;i<94;i++,j++)
	{
		abecedario[i]=j;
	}
	
}

void cargar(long long abc_int[], char abc_char[])
{
	int i,j,k;
	char n_r[30],l_r[10];
	char fichero[]="\\cifrador y descifradorDocumento2.txt";//Es el de los numeros
	char fichero2[]="\\cifrador y descifradorDocumento1.txt";//Es el de los caracteres
	FILE *numeros,*caracteres;
	numeros=fopen(fichero,"r");
	caracteres=fopen(fichero2,"r");
	if(numeros!=NULL && caracteres!=NULL)
	{
		for(i=0;i<94;i++)
		{
			abc_char[i]=fgetc(caracteres);
		}
		for(i=0;i<94;i++)
		{
			fgets(n_r,30,numeros);
			abc_int[i]=atoi(n_r);
		}
		
	}		
}
int main(void)
{
	char abecedario_ord[94];
	char mensaje_cif[1000];
	long long abc_int_cargado[94];
	char abc_char_cargado[94];
	long long phi,n;
		int i,j,k;
	long long cif;
	long long rec;
	char cadena[20];
	char mensaje[1000];
	char fichero[]="\\cifrador y descifradorcifrado.txt";
	char fichero2[]="\\cifrador y descifradorclaves.txt";
	int cont=0;//sirve para el numero de digitos del binario
	int caracteres=0;
	int e,d,x,opc;
	int num_carac;
		int *a,*b;
	FILE *arch,*arch_2;
	x=0;
	cargar(abc_int_cargado,abc_char_cargado);
		arch_2=fopen(fichero2,"r");
		ord(abecedario_ord);
		if(arch_2!=NULL)
		{
			fgets(cadena,20,arch_2);
			phi=atoi(cadena);
			fgets(cadena,20,arch_2);
			e=atoi(cadena);
			fgets(cadena,20,arch_2);
			n=atoi(cadena);
			fgets(cadena,20,arch_2);
			num_carac=atoi(cadena);
			fclose(arch_2);
		}
		d=0;
		while(1)
		{
			
			d=(1-(x*phi))/e;
			if(d*e==(1-(x*phi)))
			break;
			x-=1;
			
		}
		printf("Descifrador de mensajes cifrados por RSA:\n\n\n");

	while(d!=0)
	{
		b=(int*)calloc(cont,sizeof(int));
		for(i=0;i<cont;i++)
		{
			b[i]=a[i];
		}
		
		cont++;
		a=(int*)calloc(cont,sizeof(int));
		for(i=0;i<cont-1;i++)
		{
			a[i]=b[i];
		}
		a[cont-1]=d%2;
		d/=2;
		//printf("%d\n",a[cont-1]);
	}
	
	printf("Opciones:\n\n");
	printf("1.-Introducir la cadena por teclado\n");
	printf("2.-Recuperar de archivo\n");
	scanf("%d",&opc);
	printf("Mensaje Cifrado:\n\n");
	switch(opc)
	{
		case 1:
				printf("Introduce el texto cifrado:\n");
				scanf("%s",mensaje_cif); 
		break;
		case 2:
			arch=fopen(fichero,"r");
			if(arch!=NULL)
			{
				fgets(mensaje_cif,1000,arch);
				puts(mensaje_cif);
				fclose(arch);
				
			}
		break;
		default:
			printf("\nLa opcion itroducida no fue valida\n");
	}
	

	
		i=0;
		while(i<strlen(mensaje_cif))//Sirve para recorrer toda la frase
		{

			for(k=0;k<94;k++)
			{
				if(mensaje_cif[i]==abc_char_cargado[k])
				{
					rec=abc_int_cargado[k];
					break;
				}
			}
			
			for(j=cont-1;j>-1;j--)
			{
				if(j==cont-1)
				{	
					cif=(pow(rec,2));
					
					cif%=n;
							
				}
				else if(j==0)
				{
					if(a[j]==1)
					{
						
						cif=cif*rec;
						cif%=n;
					}
				}	
				else
				{
					if(a[j]==0)
					{
						cif=pow(cif,2);
						cif%=n;					
					}	
					else
						
					{	
						cif=(rec*cif)%n;
						cif=(pow((cif),2));
						cif%=n;
				
					}
				}

			}

		mensaje[i]=cif;

		i++;
		}
			
		puts("\n\nDESCIFRADO:");
		
		for(i=0;i<strlen(mensaje_cif);i++)
		{
			printf("%c",mensaje[i]);
		}
	
	return 1;
}
