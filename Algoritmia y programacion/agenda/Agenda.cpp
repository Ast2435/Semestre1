/*
	Name: programa 9
	Copyright: 
	Author: Martha Leticia Millan Sanches && Jesus Arturo Araiza Grijalva
	Date: 28/10/16 18:14
	Description: agenda
*/




#include <stdio.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <string.h> 
#include "Funciones.h"

struct agenda{ 
	   int numero_ID;
       int boleta;
       char nombre[50];
       char apell_pater[50];
       char apell_mater[50];
       int calificacion;
       };
       
       typedef struct agenda contacto;
       contacto contactos[50];
       
void ingresar_contacto(void);
void consultar_contacto(void);
void borrar_contacto(void);
void disco(void);
int num_contactos=0;

FILE *file; 
       
main(){
		
     int opcion, volver, salir;
      
     menu();
     opcion=op();
     
      switch(opcion){ 
            case 1:
                ingresar_contacto(); // Función para ingresar contacto
                printf("\n\nVolver a men\243 principal?\n");
                printf("Pulse 1 para s\241.\nOtra tecla para cancelar. ");
                fflush(stdin);
                scanf("%d",&volver);
                if(volver==1)
                main(); break;
            case 2: // Consultar un dato
                consultar_contacto(); // Función para consultar contacto
                printf("\n\nVolver a men\243 principal?\n");
                printf("Pulse 1 para s\241.\nOtra tecla para cancelar. ");
                fflush(stdin);
                scanf("%d",&volver);
                if(volver==1)
                main(); break;
            case 3: // Borrar contacto
                borrar_contacto(); // Función para borrar contacto
                printf("\n\nVolver a men\243 principal?\n");
                printf("Pulse 1 para s\241.\nOtra tecla para cancelar. ");
                fflush(stdin);
                scanf("%d",&volver);
                if(volver==1)
                main(); break;
            case 4: // añadir recordatorio
            	disco(); // función de recordatorio
            	printf("\n\nVolver a men\243 principal?\n");
                printf("Pulse 1 para s\241.\nOtra tecla para cancelar. ");
                fflush(stdin);
                scanf("%d",&volver);
                if(volver==1)
                main(); break;
            case 5: // Salir de la Agenda
                int salir;
                system("cls");
                printf("\n\nSalir del programa?\n");
                printf("Pulse 1 para salir.\nOtra tecla para cancelar. ");
                scanf("%d", &salir);
                if(salir!=1){
                        main();
                    }
                else{
                    break; // Automaticamente sale del Programa
                }   break;
            default: // Por si se ingresa una opción no válida
                printf("Ingreso una opci\242n inv\240lida, presione enter para volver al men\243");
                getch();
                main(); break; 
		}
      
	  getch();
      
}

void ingresar_contacto(void){ //Funcion para Ingresar Contacto

     // Declarando las Variables
     int MAX=50;
     
     system("cls");
     printf("\tINGRESANDO CONTACTO\n\n");
     
     if(num_contactos==MAX){
          printf("\tAGENDA LLENA\n");
          } 
     else{
          num_contactos++; 
          system("cls"); 
          printf("Alumno numero: %d\n", num_contactos); 
          fflush(stdin); 
          contactos[num_contactos].numero_ID = num_contactos; 
          
          printf("boleta: \n"); 
          fflush(stdin); 
          scanf("%s",&contactos[num_contactos].boleta);   
		        
          printf("Nombre del alumno: "); 
          fflush(stdin); 
          scanf("%s", contactos[num_contactos].nombre); 
                        
          printf("Apellido Paterno de %s: ", contactos[num_contactos].nombre); 
          fflush(stdin); 
          scanf("%s", contactos[num_contactos].apell_pater); 
                        
          printf("Apellido Materno de %s: ", contactos[num_contactos].nombre); 
          fflush(stdin); 
          scanf("%s", contactos[num_contactos].apell_mater); 
                        
          printf("Calificacion: "); 
          fflush(stdin); 
          scanf("%d",&contactos[num_contactos].calificacion); 
          }
     }

void consultar_contacto(void){ //Función para Consultar Contacto
	int i;
     // Declarando las Variables
     int num_deconsulta;
     system("cls");
     printf("\tREALIZANDO CONSULTA\n\n");

     for(i=1;i<50;i++)
     {
           printf("Nombre: %s %s %s\n", contactos[i].nombre, contactos[i].apell_pater, contactos[i].apell_mater);
           printf("Calificacion: %d\n", contactos[i].calificacion);       
           
     }
     }
     
void borrar_contacto(void){ // Función para Borrar Contacto

     //Declarando las Variables
     int elim_contacto, deseo_eliminar;
     char espacio_vacio[]="";
     system("cls");
     printf("ELIMINAR ALUMNO\n\n");
     
     printf("\n\n\tIngrese el numero del alumno que desee eliminar: ");
     fflush(stdin); 
     scanf("%d",&elim_contacto);
     
     if(elim_contacto==contactos[elim_contacto].numero_ID){
           printf("Nombre: %s %s %s\n", contactos[elim_contacto].nombre, contactos[elim_contacto].apell_pater, contactos[elim_contacto].apell_mater);
           printf("Confirma que desea borrar al alumno?\n");
           printf("Pulse 1 para s\241.\nOtra tecla para cancelar. ");
           fflush(stdin);
           scanf("%d", &deseo_eliminar);
           
           if(deseo_eliminar==1){
                 strcpy(contactos[elim_contacto].nombre,espacio_vacio);
                 strcpy(contactos[elim_contacto].apell_pater,espacio_vacio);
                 strcpy(contactos[elim_contacto].apell_mater,espacio_vacio);
                 contactos[elim_contacto].calificacion=0;
                 printf("Se ha eliminado el alumno\n");
                 num_contactos--;
                 }
           else {
            printf("Ha cancelado la eliminaci\242n\n");
                 }
           }
     else{
     	printf("alumno inexistente");
           }
}

void disco(void){ 
	int i;
	char disco[5000];
	file = fopen("disco.txt","r");
	if(file==NULL){
		
	file = fopen("disco.txt","a");
	
		for(i=1;i<50;i++)
     	{
     	     printf("Boleta: %d",contactos[i].boleta);
          	 printf("Nombre: %s %s %s\n", contactos[i].nombre, contactos[i].apell_pater, contactos[i].apell_mater);
          	 printf("Calificacion: %d\n", contactos[i].calificacion);   
			fflush(stdin);    
            gets(disco);
			fprintf(file, "%s\n",disco);                                 
     	}
	}
	else{

	file = fopen("disco.txt","a");
		for(i=1;i<=num_contactos;i++)
	{
		for(i=1;i<50;i++)
     	{
     	     printf("Boleta: %d",contactos[i].boleta);
          	 printf("Nombre: %s %s %s\n", contactos[i].nombre, contactos[i].apell_pater, contactos[i].apell_mater);
          	 printf("Calificacion: %d\n", contactos[i].calificacion);       
            gets(disco);
			fprintf(file, "%s\n",disco);                                 
     	}
	}
	}

	
	fclose(file);
}     

