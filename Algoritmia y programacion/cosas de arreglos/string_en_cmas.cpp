#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
	string palabra1="", palabra2="";
	int xi=0,n=0, opc=0,bandera=1;
	int c;
	cout<<"uso de String con C++"<<endl;
	cout<<"menu:"<<endl;
	cout<<"1) dar palabra 1"<<endl;
	cout<<"2) dar palabra 2"<<endl;
	cout<<"3) desplegar ambas palabras"<<endl;
	cout<<"4) comparar palabras"<<endl;
	cout<<"5) evaluar sin estan vacias las palabras"<<endl;
	cout<<"6) despelgar una parte de la palabra 1"<<endl;
	cout<<"7) concatenar palabras"<<endl;
	cout<<"8) borrar palabra 1"<<endl;
	cout<<"9) borrar palabra 2"<<endl;
	cout<<"10) salir"<<endl<<endl;
	
	do
	{
		cout<<"elija su opcion"<<endl;
		cin>>opc;
		fflush(stdin);
		switch(opc)
		{
			case 1:
				cout<<"escriba una palabra u oracion"<<endl;
				getline(cin,palabra1,'\n');
				break;
			case 2:
				cout<<"escriba una palabra u oracion"<<endl;
				getline(cin,palabra2,'\n');
				break;
			case 3:
				cout<<"palabra 1: "<<palabra1<<"\npalabra 2: "<<palabra2<<endl;
				break;
			case 4:
				if(palabra1==palabra2)
				{
					cout<<"palabra 1 es igual a palabra 2"<<endl;
				}
				else
				{
					if(strcmpi(palabra1.c_str(), palabra2.c_str())==0)
					{
						cout<<"palabra 1 es igual a palabra 2 ignorando minusculas o mayusculas"<<endl;
					}
					else
					{
						cout<<"palabra 1 es diferente a palabra 2"<<endl;
					}
				}
				break;
			case 5:
				if(palabra1.empty()==true)
				{
					cout<<"palabra 1 esta vacia"<<endl;
				}
				else
				{
					cout<<"palabra 1 no esta vacia"<<endl;
				}
				if(palabra2.empty()==true)
				{
					cout<<"palabra 2 esta vacia"<<endl;
				}
				else
				{
					cout<<"palabra 2 no esta vacia"<<endl;
				}
				break;
			case 6:
				cout<<"cuantas letras quiere tomar"<<endl;
				cin>>n;
				fflush(stdin);
				cout<<"desde que posicion quiere despelgar la parte de una palabra?"<<endl;
				cin>>xi;
				fflush(stdin);
				cout<<"la parte que escogio es: "<<palabra1.substr(xi,n);
				break;
			case 7:
				palabra1+=" "+palabra2;
				break;
			case 8:
				palabra1="";
				break;
			case 9:
				palabra2="";
				break;
			case 10:
				bandera=0;
				break;
		}
	}while(bandera==1);
}
