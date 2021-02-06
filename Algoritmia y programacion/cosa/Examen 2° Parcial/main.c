/*
 INSTITUTO POLITÉCNICO NACIONAL
 ESCUELA SUPERIOR DE CÓMPUTO
ESTRUCTURAS DE DATOS
GRUPO: 1CV9
 ALUMNO:
GUERRERO ESQUEDA OSCAR IVAN
 PROFESOR: BENJAMÍN LUNA BENOSO
EXAMEN 2° PARCIAL
FECHA: 10 DE OCTUBRE 2016 
*/
#include <stdio.h>
#include <stdlib.h>
#include "LDE.h"

void principal();

int main(int argc, char *argv[]) {
	printf("2° Examen Parcial EDD\nDadas 2 Listas Doblemente Enlazadas, crear otra (cab3) en donde sus elementos seran los elementos de las primeras 2 intercalados\n\n");
	principal();
	return 0;
}

void principal(){
	NODO* cab1=NULL;
	NODO* cab2=NULL;
	NODO* cab3=NULL;
	int num,i,j,k,l,x,y,a,b;
	printf("Para fines practicos las 2 cabeceras tendran el mismo numero de elementos\n\n");
	printf("Cuantos elementos tendran las listas?\n");
	scanf("%i",&num);
	printf("Inserta los de la primera lista (cab1):\n");
	for (i=0;i<num;i++){
		scanf("%i",&x);
		IngresarCabLDE(x,&cab1);
	}
	printf("Tu primera lista es la siguiente: ");
	ImprimirLDE(cab1);
	printf("\n\nAhora ingresa los de la segunda lista (cab2):\n");
	for (j=0;j<num;j++){
		scanf("%i",&y);
		IngresarCabLDE(y,&cab2);
	}
	printf("La segunda quedo asi: ");
	ImprimirLDE(cab2);
	
	printf("Ahora se resuelve el problema\n\n");
	
	NODO* ptr1=cab1;
	NODO* ptr2=cab2;
	for(ptr2=cab2;ptr2;ptr2->adelante){
			a=ptr1->dato;
			b=(ptr2->dato)+(ptr2->adelante->dato);
			if(a==b){
				IngresarCabLDE(b,&cab2);
				EliminarLDE(a,&cab1);
		}
		ptr1=ptr1->adelante;
	}
	printf("La lista queda asi: ");
	ImprimirLDE(cab2);
	
	
	/*printf("\n\nAhora se intercaladan: ");
	
	NODO* ptr1=cab1;
	NODO* ptr2=cab2;
	
	for(;ptr1;ptr1=ptr1->adelante){
		a=ptr1->dato;
		IngresarCabLDE(a,&cab3);
		b=ptr2->dato;
		IngresarCabLDE(b,&cab3);
		ptr2=ptr2->adelante;
	}
	ImprimirLDE(cab3);*/
}
