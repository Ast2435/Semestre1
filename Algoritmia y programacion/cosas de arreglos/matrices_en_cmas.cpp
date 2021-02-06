#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>

using namespace std;
int i, j, filas, columnas;
//funcion para desplegar la matriz
//importante &matriz ya quecon el simbolo se esta refiriendo a la direccion de la matriz original
void desplegar(vector<vector<int> > &matriz)
{
	for(i=0;i<matriz.size();i++)//usamos la funcion size() que devuelve el tamaño del arreglo
	{
		for(j=0;j<matriz[i].size();j++)
		{
			cout<<matriz[i][j]<<"\t";
		}
		cout<<endl;
	}
}
//funcion que ingresa numeros aleatorios a la matriz
void meter(vector<vector<int> > &matriz)
{
	for(i=0;i<matriz.size();i++)
	{
		for(j=0;j<matriz[i].size();j++)
		{
			matriz[i][j]=rand()%500;
		}
	}
}
//funcion para cambiar el numero de filas y de columnas
void redimensionar(vector<vector<int> > &matriz)
{
	cout<<"asigne el nuevo numero de filas"<<endl;
	cin>>filas;
	
	cout<<"asigne el nuevo numero de columnas"<<endl;
	cin>>columnas;
	
	matriz.resize(filas);
	for(i=0;i<matriz.size();i++)
	{
		matriz[i].resize(columnas);
	}
}

int main()
{
	int x, y, n;
	int bandera=1, opc;
	vector<vector<int> >A;
	vector<int> v;
	
	srand(time(NULL));
	
	cout<<"matrices en c++ con vectores"<<endl;
	
	cout<<"asigne el numero de filas"<<endl;
	cin>>filas;
	
	cout<<"asigne el numero de columnas"<<endl;
	cin>>columnas;
	//le asignamos el tamaño a la matriz
	A.resize(filas);
	for(i=0;i<filas;i++)
	{
		A[i].resize(columnas);
	}
	
	cout<<"menu:"<<endl;
	cout<<"1)desplegar"<<endl;
	cout<<"2)meter numeros aleatorios"<<endl;
	cout<<"3)cambiar tamaño"<<endl;
	cout<<"4)borrar una fila"<<endl;
	cout<<"5)borrar una columna"<<endl;
	cout<<"6)borrar una sucesion de filas"<<endl;
	cout<<"7)borrar una sucesion de columnas"<<endl;
	cout<<"8)insertar una fila"<<endl;
	cout<<"9)insertar una columna"<<endl;
	cout<<"10)insertar una fila n veces"<<endl;
	cout<<"11)insertar una columna n veces"<<endl;
	cout<<"12)limpiar"<<endl;
	cout<<"13)salir"<<endl<<endl;
	
	do
	{
		cout<<"seleccione una opcion"<<endl;
		cin>>opc;
		
		switch(opc)
		{	
			case 1:
				desplegar(A);
				break;
			case 2:
				meter(A);
				break;
			case 3:
				redimensionar(A);
				break;
			case 4:
				cout<<"increse la fila a borrar"<<endl;
				cin>>y;
				A.erase(A.begin()+y-1);
				break;
			case 5:
				cout<<"increse la columna a borrar"<<endl;
				cin>>x;
				//para borrar las columnas es necesario borrar para cada fila la posicion indicada
				//asi borrando la columna completa
				for(i=0;i<A.size();i++)
				{
					A[i].erase(A[i].begin()+x-1);
				}
				break;
			case 6:
				cout<<"increse la primer fila a borrar"<<endl;
				cin>>y;
				cout<<"increse el numero de filas a borrar"<<endl;
				cin>>n;
				//en este caso se fija la posicion fila con la posicion inicial mas el numero de filas que el usuario quiso borrar
				A.erase(A.begin()+y-1,A.begin()+y+n-1);
				break;
			case 7:
				cout<<"increse la columna a borrar"<<endl;
				cin>>x;
				cout<<"increse el numero de columnas a borrar"<<endl;
				cin>>n;
				//igual al caso 5 mas el caso 6
				for(i=0;i<A.size();i++)
				{
					A[i].erase(A[i].begin()+x-1,A[i].begin()+x+n-1);
				}
				break;
			case 8:
				cout<<"increse posicion de la fila que quiere agregar"<<endl;
				cin>>y;
				//aqui es necesario un vector auxiliar al que se le da el tamaño del numero de columnas
				//y luego a la matriz se le inserta en la posicion seleccionala el vector
				v.resize(A[1].size());
				A.insert(A.begin()+y-1,v);
				break;
			case 9:
				cout<<"increse posicion de la columna que quiere agregar"<<endl;
				cin>>x;
				for(i=0;i<A.size();i++)
				{
					A[i].insert(A[i].begin()+x-1,0);
				}
				break;
			case 10:
				cout<<"increse posicion de la fila que quiere agregar"<<endl;
				cin>>y;
				cout<<"increse el numero de filas que quiere agregar"<<endl;
				cin>>n;
				
				v.resize(A[1].size());
				A.insert(A.begin()+y-1,n,v);
				break;
			case 11:
				cout<<"increse posicion de la columnas que quiere agregar"<<endl;
				cin>>x;
				cout<<"increse el numero de columnas que quiere agregar"<<endl;
				cin>>n;
				
				for(i=0;i<A.size();i++)
				{
					A[i].insert(A[i].begin()+x-1,n,0);
				}
				break;
			case 12:
				//para limbiar el matriz primero se limpian todos los bloques de cada fila
				for(i=0;i<A.size();i++)
				{
					A[i].clear();
				}
				//y por ultimo limpio la fila completa
				A.clear();
				break;
			case 13:
				bandera=0;
				break;
		}
		v.clear();
	}while(bandera==1);
	return 1;
}
