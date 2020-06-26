#include "menu.h"
#include <iostream>

using namespace std;

Menu::Menu(Lista<Pelicula>* vistas, Lista<Pelicula>* no_vistas, Lista<Pelicula>* recomendadas){
    peliculas_vistas = vistas;
    peliculas_no_vistas = no_vistas;
    peliculas_recomendadas = recomendadas;
}

void Menu::mostrar(){
    cout << "Opciones disponibles: " << endl;
    cout << "1) Mostrar las peliculas ya vistas." << endl;
    cout << "2) Mostrar las peliculas NO vistas." << endl;
    cout << "3) Mostrar las peliculas recomendadas." << endl;
    cout << "4) Salir." << endl;
    cout << " " << endl;
}

void Menu::ir_a_opcion(int opcion){
    switch(opcion){
        case 1: /* mostrar peliculas_vistas */ ; break;
        case 2: /* mostrar peliculas_no_vistas */; break;
        case 3: /* mostrar peliculas_recomendadas */ ; break;
    }
}