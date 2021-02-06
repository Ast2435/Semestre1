#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
char cad[99999];
int arreglo[99999],ph[99999],ph2[99999],index=0, i,j,temp,q=0,s=0,s14;
printf("Digite el numero para checar sus criterios de divisibilidad:\n");
scanf("%s",&cad);
for(i = 0; i < strlen(cad); i++) //Lee la longitud del numero
{
if(cad[i]>='0' && cad[i]<='9') 
{
arreglo[index] = cad[i] - '0'; // El - '0' para pasar a int
index++;
} 
else 
{
printf("%d no es un numero\n",cad[i]);
}
}
index--;

//criterios de divisibilidad.

// 2/a
if(arreglo[index]==0 || arreglo[index]%2==0)
{
	printf("2: Si es divisible entre 2\n\n");
}
else
{
	printf("2: No es divisible entre 2\n\n");
}
// 3/a
temp=index;
for(i=0;i<=temp;i++)
{
s=s+arreglo[i];
}
if(s%3==0)
{
	printf("3: Si es divisible entre 3\n\n");
}
else
{
	printf("3: No es divisible entre 3\n\n");
} 
// 4/a
q=(arreglo[index-1]*10)+(arreglo[index]);

if(q%4==0 && q%4==0)
{
	printf("4: Si es divisible entre 4\n\n");
}
else
{
	printf("4: No es divisible entre 4\n\n");
}
// 5/a
if(arreglo[index]==0 || arreglo[index]==5)
{
	printf("5: Si es divisible entre 5\n\n");
}
else
{
	printf("5: No es divisible entre 5\n\n");
}
// 6/a
if(arreglo[index]%2==0 && s%3==0)
{
	printf("6: Si es divisible entre 6\n\n");
}
else
{
	printf("6: No es divisible entre 6\n\n");
}
// 7/a
	int s7=0;
	int guard;
	temp=index;
	temp=guard;
	for(i=0;i<=guard;i++)
	{
		ph[i]=(pow(-1,i))*(arreglo[temp]+3*arreglo[temp-1]+2*arreglo[temp-2]);
		temp=temp-3;
	}

	for(i=0;i<=guard;i++)
	{
		s7=s7+ph[i];
	}
	s14=s7;
	if(s7%7==0)
	{
		printf("7: Si es divisible entre 7\n\n");
	}
	else
	{	
		printf("7: No es divisible entre 7\n\n");
	}
// 8/a
q=(arreglo[index-2]*100)+(arreglo[index-1]*10)+(arreglo[index]);


if(q%8==0)
{
	printf("8: Si es divisible entre 8\n\n");
}
else
{
	printf("8: No es divisible entre 8\n\n");
}
// 9/a
if(s%9==0)
{
	printf("9: Si es divisible entre 9\n\n");
}
else
{
	printf("9: No es divisible entre 9\n\n");
}
// 10/a
if(arreglo[index]==0)
{
	printf("10: Si es divisible entre 10\n\n");
}
else
{
	printf("10: No es divisible entre 10\n\n");
}
// 11/a
int sp11=0;
int si11=0;
for(i=0;i<=index;i=i+2)
{
	si11=si11+arreglo[i];
}
for(j=1;j<=index;j=j+2)
{
	sp11=sp11+arreglo[j];
}
if((sp11-si11)==0 || (sp11-si11)%11==0) 
{
	printf("11: Si es divisible entre 11\n\n");
}
else
{
	printf("11: No es divisible entre 11\n\n");
}
// 12/a
q=(arreglo[index-1]*10)+(arreglo[index]);

if(s%3==0 && q%4==0 && q%4==0)
{
	printf("12: Si es divisible entre 12\n\n");
}
else
{
	printf("12: No es divisible entre 12\n\n");
}
// 13/a
int s13;
for(i=0;i<=index;i++)
{
	s13=((arreglo[index]*1)+(arreglo[index-1]*-3)+(arreglo[index-2]*-4)+(arreglo[index-3]*-1)+(arreglo[index-4]*3)+(arreglo[index-5]*4));
}
if(s13==0 || s13%13==0)
{
	printf("13: Si es divisible entre 13\n\n");
}
else
{
	printf("13: No es divisible entre 13\n\n");
}
// 14/a 
if(arreglo[index]%2==0 && s14%7==0)
{
	printf("14: Si es divisible entre 14\n\n");
}
else
{
	printf("14: No es divisible entre 14\n\n");
}

// 15/a
if(s%3==0 && arreglo[index]==0 || arreglo[index]==5)
{
	printf("15: Si es divisible entre 15\n\n");
}
else
{
	printf("15: No es divisible entre 15\n\n");
}
// 16/a
q=((arreglo[index-3]*1000)+(arreglo[index-2]*100)+(arreglo[index-1]*10)+(arreglo[index]));

if(q%16==0)
{
	printf("16: Si es divisible entre 16\n\n");
}
else
{
	printf("16: No es divisible entre 16\n\n");
}
// 17/a 
int p;
temp=index;
q=0;
q=(q+arreglo[index]*1+arreglo[index-1]*10);

for(p=-2;p>=temp*(-1);p--)
{
q=(q+arreglo[index-i]*p);
}

if(q%17==0 || q==0)
{
	printf("17: Si es divisible entre 17\n\n");
}
else
{
	printf("17: No es divisible entre 17\n\n");
}
// 18/a
if(s%9==0 && arreglo[index]%2==0)
{
	printf("18: Si es divisible entre 18\n\n");
}
else
{
	printf("18: No es divisible entre 18\n\n");
}
// 19/a 
for(j=0;j<=9999;j++)
	{
		ph[j]=0;
		ph2[j]=0;
	}
	int s19=0;
	guard=index;
	temp=guard;
	for(i=0;i<=guard;i++)
	{
		ph2[i]=((1*arreglo[temp])+(10*arreglo[temp-1])+(5*arreglo[temp-2])+(-7*arreglo[temp-3])+(6*arreglo[temp-4])+(3*arreglo[temp-5])+(-8*arreglo[temp-6])+(-4*arreglo[temp-7])+(-2*arreglo[temp-8])+(-1*arreglo[temp-9])+(9*arreglo[temp-10])+(-5*arreglo[temp-11])+(7*arreglo[temp-12])+(-6*arreglo[temp-13])+(-3*arreglo[temp-14])+(8*arreglo[temp-15])+(4*arreglo[temp-16])+(2*arreglo[temp-17]));
		temp=temp-18;
	}

	for(i=0;i<=guard;i++)
	{
		s19=s19+ph2[i];
	}
	if(s19%19==0)
	{
		printf("19: Si es divisible entre 19\n\n");
	}
	else
	{	
		printf("19: No es divisible entre 19\n\n");
	}
// 20/a
q=(arreglo[index-1]*10)+(arreglo[index]);

if(q%20==0 || arreglo[index-1]==0 && arreglo[index]==0)
{
	printf("20: S\241 es divisible entre 20\n\n");
}
else
{
	printf("20: No es divisible entre 20\n\n");
}
return 0;
}
