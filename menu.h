#ifndef TP4_ALGO2_MENU_H
#define TP4_ALGO2_MENU_H

#include "lista.h"
#include "pelicula.h"

class Menu{

private:
    Lista<Pelicula>* peliculas_vistas;
    Lista<Pelicula>* peliculas_no_vistas;
    Lista<Pelicula>* peliculas_recomendadas;

public:
    // Constructor
    // Pre: las listas debe estar inicializada
    // Post: inicializa a los atributos peliculas_vistas y peliculas_no_vistas
    Menu(Lista<Pelicula>* vistas, Lista<Pelicula>* no_vistas , Lista<Pelicula>* recomendadas);

    //Post: Imprime el menu de opciones.
    void mostrar();

    // PRE: opcion debe ser 1, 2 o 3.
    // POST: Segun el valor de opcion se hace lo siguiente:
    // Si opcion == 1 muestra peliculas_vistas
    // Si opcion == 2 muestra peliculas_no_vistas
    // Si opcion == 3 muestra peliculas_recomendadas
    void mostrar_lista(int opcion);

};


#endif //TP4_ALGO2_MENU_H