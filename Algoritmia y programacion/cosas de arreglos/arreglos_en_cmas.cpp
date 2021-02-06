#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>

using namespace std;
int i;
//importente ponerlo como const
void desplegar(vector<int> &arreglo)
{
	for(i=0;i<arreglo.size();i++)
	{
		cout<<"["<<i+1<<"]"<<arreglo[i]<<" ";
	}
	cout<<endl;
}
//muy importante pasar el vector como referencia para que lo que se haga en la funcion este en elvector real
void insertar(vector<int> &arreglo)
{
	for(i=0;i<arreglo.size();i++)
	{
		arreglo[i]=rand()%100;
	}
}

int main()
{
	int bandera=1,opc;
	int longitud,xi,xf,numero,n;
	vector<int>A(10,0);
	srand(time(NULL));
	
	cout<<"arreglos en c++ con vectores"<<endl;
	cout<<"menu:"<<endl;
	cout<<"1)desplegar"<<endl;
	cout<<"2)meter numeros aleatorios"<<endl;
	cout<<"3)cambiar tamaño"<<endl;
	cout<<"4)borrar el ultimo dato"<<endl;
	cout<<"5)borrar un dato en x posicion"<<endl;
	cout<<"6)borrar una sucesion de datos"<<endl;
	cout<<"7)insertar un dato en una nueva posicion"<<endl;
	cout<<"8)insertar un dato en x posicion"<<endl;
	cout<<"9)insertar un dato n veces"<<endl;
	cout<<"10)limpiar"<<endl;
	cout<<"11)salir"<<endl;
	do
	{
		cout<<"\nque desea hacer?"<<endl;
		cin>>opc;
		
		switch(opc)
		{
			case 1:
				desplegar(A);
				break;
			case 2:
				insertar(A);
				break;
			case 3:
				cout<<"asigne el nuevo tamaño del arreglo A"<<endl;
				cin>>longitud;
				A.resize(longitud);
				break;
			case 4:
				A.pop_back();//la funcion pop_back elimina la ultima posicion del arreglo
				break;
			case 5:
				cout<<"ingrese la posicion del elemento a borrar"<<endl;
				cin>>xi;
				A.erase(A.begin()+xi-1);
	//la funcion erase toma como parametros posiciones 
	//para ello usamos la funcion begin que devuelve la posicion inicial y se le puede sumar un numero lo que le suma las posiciones
	//el primer parametro es de inicio y se de la forma x-1 porque borrara en la posicion siguiente a la inicial
				break;
			case 6:
				cout<<"ingrese la posicion inicial de los elementos a borrar"<<endl;
				cin>>xi;
				cout<<"ingrese la posicion final de los elementos a borrar"<<endl;
				cin>>xf;
				A.erase(A.begin()+xi-1,A.begin()+xf);
	//aqui pasa igual que al borrar solo 1 dato pero ahora la posicion final es la que da el usuario
				break;
			case 7:
				cout<<"ingrese el nuevo valor"<<endl;
				cin>>numero;
				A.push_back(numero);//ingresa el valor en una nueva posicion hasta el final
				break;
			case 8:
				cout<<"teclee el numero que desea insertar"<<endl;
				cin>>numero;
				cout<<"teclee la posicion donde desea insertar el numero"<<endl;
				cin>>xi;
				A.insert(A.begin()+xi-1,numero);
	//la funcion insert puede aceptar 2 o 3 parametros
	//si le damos 2 parametros, el primero sera la posicion donde insertaremos el dato
	//es de la misma forma que el erase
	//el segundo parametro el el valor a insertar
				break;
			case 9:
				cout<<"\nteclee el numero que desea insertar"<<endl;
				cin>>numero;
				cout<<"\nteclee la posicion donde desea insertar el numero"<<endl;
				cin>>xi;
				cout<<"\nteclee el numero de veces que quiere insertar el numero"<<endl;
				cin>>n;
				A.insert(A.begin()+xi-1,n,numero);
	//aqui el primer parametro sigue siendo la posicion
	//el segundo parametro es las veces que quiere insertar el numero
	//y el tercer parametro es el valor a insertar
				break;	
			case 10:
				A.clear();//destruye el arreglo dejandolo sin elementos dentro de el
				break;
			case 11:
				bandera=0;
				break;					
		}
	}while(bandera==1);
	return 1;
}
