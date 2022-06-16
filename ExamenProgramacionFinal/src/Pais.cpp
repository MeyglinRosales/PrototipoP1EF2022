#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "Jugador.h"
#include "Bitacora.h"

Jugador::Jugador()
{
    //ctor
}

Jugador::~Jugador()
{
    //dtor
}


void Jugador::menu()
{
    Bitacora control;
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t................................"<<endl;
	cout<<"\t\t\t .  SISTEMA DEL TIPO JUGADOR   ."<<endl;
	cout<<"\t\t\t................................"<<endl;
	cout<<"\t\t\t 1. Ingreso Jugador"<<endl;
	cout<<"\t\t\t 2. Actualizar Jugador"<<endl;
	cout<<"\t\t\t 3. Consultar Jugador"<<endl;
	cout<<"\t\t\t 4. Imprimir Jugador"<<endl;
	cout<<"\t\t\t 5. Borrar Jugador"<<endl;
	cout<<"\t\t\t 6. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t Opcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    	    control.nuevaActividadTxt(25);
            control.nuevaActividad(25);
    		Ingresar();
    		cout<<"\n\t\t\t Agrega otro Jugador(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		cout <<"Jugador agregados satisfactoriamente"<<endl;
		break;
	case 2:
	    control.nuevaActividadTxt(26);
        control.nuevaActividad(26);
		Actualizar();
		cout <<"Jugador actualizado satisfactoriamente"<<endl;
		break;
	case 3:
	    control.nuevaActividadTxt(27);
        control.nuevaActividad(27);
		Consultar();
		cout <<"Presiona Enter para salir"<<endl;
		break;
	case 4:
	    control.nuevaActividadTxt(28);
        control.nuevaActividad(28);
		Imprimir();
		cout <<"Impresion realizada satisfactoriamente"<<endl;
		break;
	case 5:
	    control.nuevaActividadTxt(33);
        control.nuevaActividad(33);
		Borrar();
		cout <<"Jugador eliminado satisfactoriamente"<<endl;
		break;
	case 6:
	    cout << "Presiona Enter para confirmar"<<endl;
        break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 6);
}

//Funcion que ingresa jugador
void Jugador::Ingresar()
{
    Bitacora control;
	system("cls");
	fstream file;
	cout<<"\n.....................................................................................................................";
	cout<<"\n.....................................Agregar detalles de Jugador......................................................"<<endl;
	cout<<"\t\t\tIngresa el ID del Jugador       : ";
	cin>>Djugador;
	cout<<"\t\t\tIngresa posicion de Jugador    : ";
	cin>>Cjugador;
	file.open("JUGADOR.dat", ios::out | ios::binary);
	file<<std::left<<std::setw(15)<< Djugador <<std::left<<std::setw(15)<< Cjugador << "\n";
	file.close();
    file.open("JUGADOR.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< Djugador <<std::left<<std::setw(15)<< Cjugador << "\n";
	file.close();
}

//Funcion para imprimir los datos de puestos
void Jugador::Imprimir()
{
    Bitacora control;
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n..............................Tabla de Detalles de jugador ........................"<<endl;
	file.open("JUGADOR.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> Djugador >> Cjugador;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t ID del jugador: "<<Djugador<<endl;
			cout<<"\t\t\t posicion del jugador: "<<Cjugador<<endl;
			file >> Djugador >> Cjugador;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}

//funcion para modificar jugador
void Jugador::Actualizar()
{
    Bitacora control;
	system("cls");
	fstream file,file1;
	string participant_Dp;
	int found=0;
	cout<<"\n.............................Modificacion Detalles JUGADOR................................."<<endl;
	file.open("JUGADOR.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el id del jugador a modificar: ";
		cin>>participant_Dp;
		file1.open("Record.txt",ios::app | ios::out);
		file >> Djugador >> Cjugador;
		while(!file.eof())
		{
			if(participant_Dp!=Djugador)
			{
			 file1<<std::left<<std::setw(15)<< Djugador <<std::left<<std::setw(15)<< Cjugador << "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese el ID del jugador: ";
				cin>>Djugador;
				cout<<"\t\t\tIngresa la posicion del jugador: ";
				cin>>Cjugador;

				file1<<std::left<<std::setw(15)<< Djugador <<std::left<<std::setw(15)<< Cjugador << "\n";
				found++;
			}
			file >> Djugador >> Cjugador;

		}
		file1.close();
		file.close();
		remove("JUGADOR.txt");
		rename("Record.txt","JUGADOR.txt");
	}
}

//funcion para conultar JUGADOR
void Jugador::Consultar()
{
    Bitacora control;
	system("cls");
	fstream file;
	int found=0;
	file.open("JUGADOR.txt",ios::in);
	if(!file)
	{
		cout<<"\n..................................Datos del jugador buscado......................................"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_Dp;
		cout<<"\n..................................Datos del jugador buscado......................................"<<endl;
		cout<<"\n Ingrese el ID del jugador que quiere consultar: ";
		cin>>participant_Dp;
		file >> Djugador >> Cjugador;
		while(!file.eof())
		{
			if(participant_Dp==Djugador)
			{
				cout<<"\n\n\t\t\t ID del jugador: "<<Djugador<<endl;
                cout<<"\t\t\t posicion del jugador: "<<Cjugador<<endl;
				found++;
			}
			file >> Djugador >> Cjugador;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t jugador no encontrado...";
		}
		file.close();
	}
}
void Jugador::Borrar()
{
    Bitacora control;
	system("cls");
	fstream file,file1;
	string participant_Dp;
	int found=0;
	cout<<"\n.......................................Detalles jugador a Borrar.................................."<<endl;
	file.open("Jugador.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el ID del jugador que quiere borrar: ";
		cin>>participant_Dp;
		file1.open("Record.txt",ios::app | ios::out);
		file >> Djugador >> Cjugador;
		while(!file.eof())
		{
			if(participant_Dp!= Djugador)
			{
				file1<<std::left<<std::setw(15)<< Djugador <<std::left<<std::setw(15)<< Cjugador<< "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> Djugador >> Cjugador;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t jugador no encontrado...";
		}
		file1.close();
		file.close();
		remove("JUGADOR.txt");
		rename("Record.txt","JUGADOR.txt");
	}
}


void Jugador::consultarJug()
{
    Bitacora control;
	system("cls");
	fstream file;
	int found=0;
	file.open("JUGADOR.txt",ios::in);
	if(!file)
	{
		cout<<"\n..................................Datos del jugador buscado......................................"<<endl;
		cout<<"\n\t\t\t No hay informacion...";
	}
	else
	{
		string participant_Dp;
		cout<<"\n..................................Datos del jugador buscado......................................"<<endl;
		cout<<"\n Ingrese el ID del jugador que desea ver: ";
		cin>>participant_Dp;
		file >> Djugador >> Cjugador;
		while(!file.eof())
		{
			if(participant_Dp==Djugador)
			{
				cout<<"\n\n\t\t\t ID: "<<Djugador<<endl;
                cout<<"\t\t\t Pais "<<Cjugador<<endl;

				found++;
			}
			file >> Djugador >> Cjugador;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Jugador no encontrado...";
		}
		file.close();
	}
}
