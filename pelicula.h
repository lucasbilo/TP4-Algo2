#ifndef _PELICULAS_H
#define _PELICULAS_H

#include <iostream>
#include "pelicula.h"
#include "lista.h"

const int PUNTAJE_MINIMO_RECOMENDADA = 7;

class Pelicula{

    private:
        std::string nombre;
        std::string genero;
        int puntaje;
        std::string director;
        Lista<std::string>* actores;

    public:
        //Constructor sin parametro
        // POST: Inicializa a Pelicula, sus atributos estan vacios
        Pelicula();

        // CONSTRUCTOR
        // POST: Inicializa a Pelicula, se asigna cada parametro al atributo correspondiente. Actores apunta a memoria alocada dinamicamente.
        Pelicula(std::string nombre, std::string genero, int puntaje, std::string director, Lista<std::string>* actores);

        // DESTRUCTOR
        // PRE: Pelicula creada
        // POST: Libera la memoria usada en el atributo actores.
        ~Pelicula();

        // POST: Puede devolver TRUE en 2 casos:
        // 1) puntaje >= PUNTAJE_MINIMO_RECOMENDADA
        // 2) Si vistas no es vacio: si hay coincidencia en el género y (en el director o por lo menos uno de los actores)
        // Devuelve FALSE si no se cumple ninguno de los 2 casos anteriores
        bool es_recomendada(Lista<Pelicula>* vistas);

        // PRE: peli debe estar inicializada
        // POST: Cambia los atributos de la pelicula a los atributos de la pelicula que apunta el puntero pasada por parametro
        void copiar_pelicula(Pelicula* peli);


        // POST: Muestra por pantalla lo siguiente:
        // Nombre - Genero - Puntaje - Director
        // y llama al atributo mostrar_actores()
        void mostrar();

        // POST: Devuelve un string que es el atributo nombre
        std::string obtener_nombre();

        // POST: Devuelve un string que es el atributo genero
        std::string obtener_genero();

        // POST: Devuelve un entero que es el atributo puntaje
        int obtener_puntaje();

        // POST: Devuelve un string que es el atributo director
        std::string obtener_director();

        // POST: Devuelve un puntero a una lista de string que es el atributo actores
        Lista<std::string>* obtener_actores();

    private:
        // PRE: actores->obtener_tam() > 0
        // POST: Muestra por pantalla el string de cada posicion que tiene el atributo actores
        void mostrar_actores();

        // PRE: actores_comparar no puede estar vacio
        // POST: Compara el atributo actores con la lista que apunta el parametro pasado
        // Devuelve TRUE si hay al menos 1 coincidencia, FALSE en caso contrario
        bool coincide_algun_actor(Lista<std::string>* actores_comparar);
};

#endif //_PELICULAS_H
