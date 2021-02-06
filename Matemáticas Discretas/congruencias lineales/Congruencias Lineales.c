/*
	Name: "Congruencias Lineales"
	Author: Gutierrez Beltran Jonathan Ivan
	Date: 14/10/16
	Description: \(*u*)/
*/


#include<stdio.h>

long long main(){
	system("color B");
	printf("***Congruencias Lineales***\n\n");
	long long rein=1;
	while(rein!=0){
	long long a,b,c,alfa,beta,s,k,x,i,bandera=1;

//Ingreso de valores		
printf("Ingrese valor para a: ");
scanf("%lld",&a);
system("cls");

printf("%lldx = ",a);
scanf("%lld",&c);
system("cls");
		
printf("%lldx = %lld  mod  ",a,c);
scanf("%lld",&b);
system("cls");

//Bezout
alfa=coef1(a,b);
beta=coef2(a,b);
printf("\t%lld = %lld*(%lld) + %lld*(%lld)",
alfa*a+beta*b,a,alfa,b,beta );	

if(alfa*a+beta*b==1){	
//Solucion particular
s=c*alfa;

//Solucion General
i=(-1)*b;
while(bandera!=0){
	x=s+(b*i);
	if(x>0){
		bandera=0;
	}
	else{
		i++;
	}	
}


printf("\n\n\t[K= %lld]    [X= %lld]",i,x);

//Comprobacion
printf("\n\nComprobacion a(X)= b mod m: \n\n");
printf("%lld(%lld) = %lld mod %lld",a,x,c,b);
		
}
else{
	system("cls");
	printf("No tiene solucion U.u");
}	
		
//Reinicio
	printf("\n\nDesea reiniciar? 1= Si  0= No: ");
	scanf("%lld",&rein);
	system("cls");

	}
	printf("!!Hasta Luego!!\n\n");
	
	return 0;
}



//Bezout
int coef1(long long a,long long b)
{
    if (a%b==0) return (0);
    else return (coef2(b,a%b));
}
int coef2(long long a, long long b)
{
    if (a%b==0) return(1);
    else return (coef1(b,a%b)- a/b *coef2(b,a%b));
}
