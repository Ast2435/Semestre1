#include <stdlib.h>
#include <stdio.h>


typedef int TipoDato;
typedef struct nodo{
	TipoDato dato;
	struct nodo *adelante,*atras;
}NODO;

void IngresarCabLDE(TipoDato x, NODO**cab);
void IngresarLDE(TipoDato x, NODO**anterior);
void EliminarLDE(TipoDato x, NODO**cab);
void ImprimirLDE(NODO *cab);
