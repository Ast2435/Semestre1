#include "LDE.h"

void IngresarCabLDE(TipoDato x, NODO**cab){
	NODO *nuevo=(NODO*)malloc(sizeof(NODO));
	nuevo->dato=x;
	nuevo->adelante=(*cab);
	nuevo->atras=NULL;
	if((*cab)!=NULL){
		(*cab)->atras=nuevo;
	}
	(*cab)=nuevo;
}

void IngresarLDE(TipoDato x, NODO*anterior){
	NODO *nuevo=(NODO*)malloc(sizeof(NODO));
	nuevo->dato=x;
	nuevo->adelante=anterior->adelante;
	nuevo->atras=anterior;
	anterior->adelante=nuevo;
	nuevo->adelante->atras=nuevo;
}

void EliminarLDE(TipoDato x, NODO**cab){
	int encontrado=0;
	NODO*ptr=*cab;
	while(ptr!=NULL && !encontrado){
		encontrado=(ptr->dato==x);
		if(!encontrado){
			ptr=ptr->adelante;
		}
	}
	if (encontrado){
		if(ptr==(*cab)){
			(*cab)=ptr->adelante;
			if(ptr->adelante!=NULL){
				(*cab)->atras=NULL;
			}
		}
		else if (ptr->adelante!=NULL){
			ptr->adelante->atras=ptr->atras;
			ptr->atras->adelante=ptr->adelante;
		}
		else{
			ptr->atras->adelante=NULL;
		}
		free(ptr);
	}
}

void ImprimirLDE(NODO *cab){
	NODO *ptr;
	for(ptr=cab;ptr;ptr=ptr->adelante)
		printf("%d ",ptr->dato);
}
