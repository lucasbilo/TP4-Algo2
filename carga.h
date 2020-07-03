#ifndef _CARGA_H
#define _CARGA_H

#include "lista.h"
#include "pelicula.h"

class Carga {

    private:

        Lista<Pelicula>* vistas;
        Lista<Pelicula>* no_vistas;
        Lista<Pelicula>* recomendadas;
        std::string nombre_archivo_vistas;
        std::string nombre_archivo_no_vistas;
        std::string nombre_archivo_recomendadas;

    public:

        /* Constructor Carga
        *  Post: Se inicializa cada atributo de la Carga con su correspondiente parametro recibido.
        */
        Carga(Lista<Pelicula>* vistas, Lista<Pelicula>* no_vistas, Lista<Pelicula>* recomendadas, std::string archivo_vistas, std::string archivo_no_vistas, std::string archivo_recomendadas);

        //Destructor
        ~Carga();

        /*
        * Pre: Los archivos siguen una estructura determinada por nombre, genero, puntaje, director y finalmente una lista de actores.
        * Post: Se agregan las peliculas de los archivos nombre_archivo_vistas y nombre_archivo_no_vistas en las respectivas listas.
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
