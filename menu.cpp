#include "menu.h"
#include <iostream>

using namespace std;

Menu::Menu(Lista<Pelicula>* vistas, Lista<Pelicula>* no_vistas, Lista<Pelicula>* recomendadas){
    peliculas_vistas = vistas;
    peliculas_no_vistas = no_vistas;
    peliculas_recomendadas = recomendadas;
}

Menu::~Menu(){
}


void Menu::mostrar(){
    cout << "Opciones disponibles: " << endl;
    cout << "1) Mostrar las peliculas ya vistas." << endl;
    cout << "2) Mostrar las peliculas NO vistas." << endl;
    cout << "3) Mostrar las peliculas recomendadas." << endl;
    cout << "4) Salir." << endl;
    cout << " " << endl;
}

void Menu::mostrar_lista(Lista<Pelicula>* lista){
    for(unsigned pos = 1; pos <= lista->obtener_tam(); pos++) {
        cout << "Pelicula nro " << pos << ")" << endl;
        lista->obtener_dato(pos)->mostrar();
    }
}

void Menu::mostrar_lista(int opcion) {
    switch (opcion) {
        case 1:
            mostrar_lista(peliculas_vistas);
            break;
        case 2:
            mostrar_lista(peliculas_no_vistas);
            break;
        case 3:
            mostrar_lista(peliculas_recomendadas);
            break;
    }
/*
    for(unsigned pos = 1; pos <= peliculas_vistas->obtener_tam(); pos++){
        cout << "Pelicula nro " << pos << ")" << endl;
        peliculas_vistas->obtener_dato(pos)->mostrar();
    }
*/}