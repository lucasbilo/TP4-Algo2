#ifndef _CARGA_H
#define _CARGA_H

#include "lista.h"
#include "pelicula.h"

const std::string ARCHIVO_VISTAS = "peliculas_vistas.txt";
const std::string ARCHIVO_NO_VISTAS = "peliculas_no_vistas.txt";

class Carga {

    private:

        Lista<Pelicula>* vistas;
        Lista<Pelicula>* no_vistas;
        Lista<Pelicula>* recomendadas;

    public:

        /* Constructor Carga
        *  Post: Se inicializa cada atributo de la Carga con su correspondiente parametro recibido.
        */
        Carga(Lista<Pelicula>* vistas, Lista<Pelicula>* no_vistas, Lista<Pelicula>* recomendadas);

        //Destructor
        ~Carga();

        /*
        * Pre: Los archivos siguen una estructura determinada por nombre, genero, puntaje, director y finalmente una lista de actores.
        * Post: Se agregan las peliculas de los archivos nombre_archivo_vistas y nombre_archivo_no_vistas en las respectivas listas
        *       y se agregan las peliculas de la lista de no vistas que son recomendadas a la correspondiente lista.
        */
        void cargar_datos();

    private:
        /*
        * Pre: El archivo sigue una estructura determinada por nombre, genero, puntaje, director y finalmente una lista de actores.
        * Post: Se agregan las peliculas del archivo en la lista de peliculas.
        */
        void agregar(Lista<Pelicula>* peliculas, std::ifstream& archivo);

        /*
        * Pre: El archivo de recomendadas se abrio correctamente.
        * Post: Se comparan las peliculas de la lista de no_vistas y si [hay coincidencia en el género y (en el director o por lo menos
        *       uno de los actores)] o [el puntaje es 7 o más] se agrega a la lista de recomendadas.
        */
        void agregar_recomendadas();

         /*
         * Pre: El archivo fue abierto correctamente y sigue una estructura determinada por nombre, genero, puntaje, director y finalmente una lista de actores.
         * Post: Lee una pelicula y la guarda en memoria dinamica apuntada por peli.
         */
         void leer_pelicula(std::ifstream &archivo, Pelicula* &peli);
};


#endif //_CARGA_H
