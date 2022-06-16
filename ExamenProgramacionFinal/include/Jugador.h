#ifndef JUGADOR_H
#define JUGADOR_H
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;

class Jugador
{

    public:
        string Djugador ,Cjugador;
        void menu ();
            void Ingresar();
            void Actualizar ();
            void Consultar ();
            void Imprimir ();
            void Borrar ();
            void consultarJug();

        Jugador();
        virtual ~Jugador();

    protected:

    private:
};

#endif // JUGADOR_H
