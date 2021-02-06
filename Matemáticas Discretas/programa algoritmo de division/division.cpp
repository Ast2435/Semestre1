#include<stdio.h>

int main()
{
long long int a,b,q=0,r=0;
printf("Introduzca el valor de A:");
scanf("%lld",&a);
printf("Introduzca el valor de B (Mayor que 1):");
scanf("%lld",&b);

if(a==0)
printf("El valor de r es 0 y el de q es 0");
else
{
if(b<1)
{
printf("El valor de B(%d) no es v\240lido, porfavor ingrese un valor mayor que 1:\n",b);
scanf("%lld",&b);
}

for(a>0; ;q++)
	{
		r=a-(b*q);
		
		if(r<0)
		{
		q=q-1;
		r=a-(b*(q));
		break;
		}
			
	}
for(a<0; ;q--)
	{
		r=a-(b*q);
		
		if(r>0)
		{
		r=a-(b*(q));
		break;
		}
			
	}
printf("El valor de r es %lld y el de q es %lld tales que %lld=%lld(%lld)+(%lld)\n",r,q,a,b,q,r);
printf("------------------------------------------------------------------\n");
}


return 1;
}
