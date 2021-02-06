# include <stdio.h>
# include <math.h>

void Factor_primo(long long int i)
{
//While para cuando i es par
int cont1=0;
while (i%2==0)
{
i=i/2;
cont1++;
}
if (cont1!=0)
printf("2^%d ",cont1);
//For para cuando i ya no es par
int cont2=0;
for (long long int j=3;j<=sqrt(i);j=j+1)
{
//Mientras j divide a i, imprime j y divide a i
cont2=0;
while (i%j==0)
{
i=i/j;
cont2++;
}
//Condicion para imprimir solo los factores que esten elevados a mas que 0
if (cont2!=0)
printf("%lld^%d ",j,cont2);
}
//Para cuando i es un número primo mayor que 2
if (i>2)
printf ("%lld ",i);
}

int main()
{
long long int i;
printf("Ingrese un número positivo para calcular sus factores primos:\n");
scanf("%d",&i);
while(i<0)
{
printf("El número que ingresó no es positivo, porfavor ingrese un número positivo:\n");
scanf("%d",&i);	
}
Factor_primo(i);
return 0;
}
