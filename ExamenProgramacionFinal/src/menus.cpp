#include "menus.h"
#include <iostream>
#include<conio.h>
#include "Persona.h"
#include "Bitacora.h"
#include "Puesto.h"
#include "Usuarios.h"
#include "Concepto.h"
#include "Poliza.h"
#include "Pais.h"
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ios;
using std::left;
using std::right;
using std::fixed;
using std::showpoint;

#include <ctime>
#include <vector>
#include <fstream>

using std::ofstream;
using std::ostream;
using std::fstream;

#include <iomanip>

using std::setw;
using std::setprecision;

#include <cstdlib>
using namespace std;

menus::menus()
{
    //ctor
}

menus::~menus()
{
    //dtor
}

menus::menuGeneral()
{
    Puesto gesPuesto;
    Pais gesPais;
    Bitacora control;
    menus menuG;
int choice;
	char x;
	do
    {
	system("cls");
	//Funcion que imprime Fecha  y Hora
	control.fechaHora();
	cout<<"***************************************************************************************"<<endl;
	cout<<"\t\t\t    MEYGLIN DEL ROSARIO ROSALES OCHOA, 9959-21-4490  "<<endl;
	cout<<"***************************************************************************************"<<endl;
	cout<<"\t\t\t   CORPORACION DE DEPORTES     "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consultas"<<endl;
	cout<<"\t\t\t 2. Contabilidad"<<endl;
	cout<<"\t\t\t 3. Gestion Entrenador "<<endl;
	cout<<"\t\t\t 4. Sistema Tipo Puesto"<<endl;
	cout<<"\t\t\t 5. Gestion Pais"<<endl;
	cout<<"\t\t\t 6. Tipo Juador"<<endl;
	cout<<"\t\t\t 7. Equipo "<<endl;
	cout<<"\t\t\t 8. Seguridad"<<endl;
	cout<<"\t\t\t 9. Salir"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6/7/8/9]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;
//Llamadas a los menus secundarios
    switch(choice)
    {
    case 1:
        //Se envia a la Bitacora la accion realizada por el usuario
        control.nuevaActividadTxt(1);
        control.nuevaActividad(1);
        menuConsultas();
		break;
	case 2:
        control.nuevaActividadTxt(2);
        control.nuevaActividad(2);
        menuContabilidad();
		break;
	case 3:
	    control.nuevaActividadTxt(3);
        control.nuevaActividad(3);
        menuEntrenador();
		break;
    case 4:
        control.nuevaActividadTxt(4);
        control.nuevaActividad(4);
        gesPuesto.menu();
		break;
    case 5:
        control.nuevaActividadTxt(4);
        control.nuevaActividad(4);
        gesPais.menu();
		break;
    case 6:
        control.nuevaActividadTxt(4);
        control.nuevaActividad(4);
        gesPais.menu();
		break;
    case 7:
        control.nuevaActividadTxt(4);
        control.nuevaActividad(4);
        gesPais.menu();
		break;
    case 8:
        control.nuevaActividadTxt(5);
        control.nuevaActividad(5);
        menuSeguridad();
	case 9:
	    control.nuevaActividadTxt(6);
        control.nuevaActividad(6);
        break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    }while(choice!= 9);
    return 0;
}
