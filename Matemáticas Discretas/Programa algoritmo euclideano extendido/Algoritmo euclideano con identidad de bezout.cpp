#include<stdio.h>
//Función recursiva para algoritmo euclideano extendido
long long int xmcd(long long int a, long long int b, long long int &x, long long int &y)
 {
    if(b == 0)
	 {
       x = 1;
       y = 0;
       return a;
    }

    long long int x1, y1, mcd = xmcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return mcd;
  }
int main()
{

long long int a, b, x, y, mcd, temp;
printf("Introduzca el valor (positivo) de a:\n");
scanf("%lld",&a);
while (a<0)
{
printf("El valor de a(%lld) no es v\240lido, porfavor ingrese un valor postivo para a:\n",a);
scanf("%lld",&a);
}
printf("Introduzca el valor (positivo) de b:\n");
scanf("%lld",&b);
while (b<0)
{
printf("El valor de b(%lld) no es v\240lido, porfavor ingrese un valor postivo para b:\n",b);
scanf("%lld",&b);
}

   if(a < b)
   {
   	temp=a;
   	a=b;
   	b=temp;
   }

mcd = xmcd(a, b, x, y);
	printf("el MCD es: %lld, x=%lld y y=%lld que es igual a la forma mcd(%lld,%lld)=%lld(%lld)+%lld(%lld)\n",mcd,x,y,a,b,a,x,b,y);
	printf("------------------------------------------------------------------\n");

return 1;
}
