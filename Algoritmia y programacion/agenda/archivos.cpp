//Autor: Gustavo salgado zaragoza

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int ingresar(char **&matriz)
{
	string nombre;
	int opc, i=0, boleta, calificacion;
	
	matriz=(char**)malloc(1*sizeof(char*));//arreglo dinamico
	do
	{
		cout<<"ingrese boleta: ";//ingresamos la boleta max 8 digitos
		cin>>boleta; fflush(stdin); cout<<endl;//fflush importante para el getline
		
		cout<<"ingrese el nombre: ";
		getline(cin,nombre,'\n'); fflush(stdin); cout<<endl;//getline sirve como el gets pero es de c++
		cout<<"ingrese la calificacion: ";
		cin>>calificacion; fflush(stdin); cout<<endl;
		
		matriz[i]=(char*)malloc((8+nombre.length()+2)*sizeof(char));
		sprintf(matriz[i],"%d,%s,%d\n",boleta,nombre.c_str(),calificacion+1);
		puts(matriz[i]);
		//metemos en la matriz la boleta, el nombre y la calificacion
		//string.c_str() convierte el string a un arreglo de char ya que sprintf lo necesita de esa forma
		cout<<"desea ingresar otro registro? 1)si 2)no: ";
		cin>>opc;
		fflush(stdin);
		i++;
	}while(opc==1);
	
	return i;//regresara el numero de filas de la matriz
}
void guardar(FILE *&ap_arc, char **&matriz, int f)
{
	int i;
	//creamos el archivo como append ya que se guardaran varios registros
	ap_arc=fopen("archivo01.csb","a");
	if(ap_arc==NULL)
	{
		exit(1);//sale del programa si el archivo es nulo
	}
	for(i=0;i<f;i++)
	{
		fputs(matriz[i],ap_arc);//vamos guardando los registros en cada fila de la matriz
	}
	fclose(ap_arc);
}
int main()
{
	FILE *archivo;
	string texto;
	char **matriz;
	int opc;
	int letra, filas;
	
	cout<<"Manejo de archivos"<<endl;
	
	do
	{
		cout<<"Menu:"<<endl;
		cout<<"1) ingresar texto"<<endl;
		cout<<"2) guardar texto"<<endl;
		cout<<"3) mostrar texto"<<endl;
		
		cout<<"elija una opcion: ";
		cin>>opc;
		fflush(stdin);
		
		switch(opc)
		{
			case 1:
				filas=ingresar(matriz);
				break;
				
			case 2:
				guardar(archivo,matriz,filas);
				break;
				
			case 3:
				archivo=fopen("archivo01.csb","r");
				if(archivo==NULL)
				{
					exit(1);
				}
				do
				{
					letra=fgetc(archivo);//muestra el archivo
					printf("%c",letra);
				}while(letra!=EOF);
				cout<<endl;
				break;
				
			default:
				exit(1);
				break;
		}
		cout<<"1) realizar otra accion\n2) salir"<<endl;
		cin>>opc;
		fflush(stdin);
	}while(opc==1);
	
	return 1;
}
