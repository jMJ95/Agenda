
#include "librerias.h"
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct Contacto
{
	int id;
	char nombre[30];
	char telefono[11];
};

   	void menu()
	{
		system("cls");
		cout <<" Agenda Telefonica"<<endl;
		cout << endl <<" 1 - Agregar Contactos"<<endl;
		cout << endl <<" 2 - Ver Contactos" << endl;
		cout << endl <<" 3 - Eliminar Contactos" << endl;
		cout << endl <<" 5 - Salir" << endl;
		cout << endl <<" Seleccione una opcion => ";

	}



	void guardar( int id)
	{
		system("cls");
		Contacto contacto;
		ofstream archivo;
		string nombre_archivo = "Agenda.txt";
		archivo.open(nombre_archivo.c_str(), ios::app);
		contacto.id = id;
		cin.ignore();
				cout << "Agregar Contacto" <<endl;
				cout <<endl << "Nombre: ";
				cin.getline(contacto.nombre, 30);
				cout <<endl << "Numero: ";
				cin.getline(contacto.telefono, 11);

		archivo.write((char *)&contacto, sizeof(contacto));

		archivo.close();
	}

	void verContacto()
	{
		ifstream leer_archivo("Agenda.txt");
		Contacto contacto;

		leer_archivo.read((char *)&contacto, sizeof(contacto));
		if(leer_archivo.fail())
		{
			cout <<" Ocurrio un ploblema, intentando abrir la agenda :(" <<endl;
			exit(1);
		}
		cout <<"id   Nombre     Telefono"<<endl;
		while(!leer_archivo.eof())
		{

			cout <<endl <<contacto.id <<" -> "<<  contacto.nombre << "   " <<contacto.telefono << endl;
			leer_archivo.read((char *)&contacto, sizeof(contacto));

		}
		cout << endl;
		leer_archivo.close();


	}

	void eliminarContacto(int id)
	{

		fstream leer_archivo("Agenda.txt");
		ofstream archivo("borrar.txt");
		Contacto contacto;
		leer_archivo.read((char *)&contacto, sizeof(contacto));

		if(leer_archivo.fail())
		{
			cout <<" Ocurrio un ploblema, intentando abrir la agenda :(" <<endl;
			exit(1);
		}

		while(!leer_archivo.eof())
		{

			if(contacto.id != id)
			{

				archivo.write((char *)&contacto, sizeof(contacto));
			}
			leer_archivo.read((char *)&contacto, sizeof(contacto));
		}
		cout << endl;
		leer_archivo.close();
		archivo.close();

	    remove("Agenda.txt");
		rename("borrar.txt", "Agenda.txt");



	}

int _tmain(int argc, _TCHAR* argv[])
{
int opcion = 0, salir = 0, p = 0, l = 0, id = 1;

	string nombre, numero;



	do
	{
		menu();
		cin >> opcion;

		switch (opcion)
		{

		case 1:
			do{
				system("cls");

				guardar(id);

				cout <<endl << "Quieres? " <<endl;
				cout << "1 - Seguir agregando" <<endl;
				cout << "2 - Salir" <<endl;
				cout << "Seleccione una opcion => ";
				cin >>p;
				id++;

			}while (p != 2);

			break;

		case 2:
		system("cls");
		cout << "Contactos" <<endl<<endl;
		verContacto();
	    cout <<endl<< "1 - Salir" <<endl;
		cout <<endl<< "Seleccione el 1 para salir: ";
		cin >>salir;
		if(salir == 1)
		{
			menu();
		}
			break;

		case 3:
			do{
				system("cls");
				cout << "Eliminar contactos" <<endl<<endl;
				verContacto();
				cout <<endl << "Seleccione el contacto : ";
				cin >>l;
				eliminarContacto(l);

			    cout <<endl<< "1 - Salir" <<endl;
				cout <<endl<< "2 - Seguir eliminando" <<endl;
				cout <<endl<< "Seleccione la opcion para salir: ";
				cin >>salir;
				if(salir == 1)
				{
					menu();
				}

			}while(salir != 1);
			break;

		}

	} while (opcion != 5);

	system("pause");
	return 0;
}
