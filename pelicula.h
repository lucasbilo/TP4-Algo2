#ifndef TP4_ALGO2_PELICULAS_H
#define TP4_ALGO2_PELICULAS_H

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
    Pelicula();
    Pelicula(std::string nombre, std::string genero, int puntaje, std::string director, Lista<std::string>* actores);
    ~Pelicula();
    bool es_recomendada(Lista<Pelicula>* vistas);
    std::string obtener_nombre();
    std::string obtener_genero();
    int obtener_puntaje();
    std::string obtener_director();
    Lista<std::string>* obtener_actores();
    void copiar_pelicula(Pelicula* peli);
    bool coincide_algun_actor(Lista<std::string>* actores_comparar);

    void mostrar_actores();

    // muestra los atributos de la peli
    void mostrar();

};

#endif //TP4_ALGO2_PELICULAS_H
