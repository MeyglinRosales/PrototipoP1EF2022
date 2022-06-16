#ifndef PAIS_H
#define PAIS_H
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;

class Pais
{

    public:
        string Dpais,Cpais;
        void menu ();
            void Ingresar();
            void Actualizar ();
            void Consultar ();
            void Imprimir ();
            void Borrar ();
            void consultarPais();

        Pais();
        virtual ~Pais();

    protected:

    private:
};

#endif // PAIS_H
