#ifndef _CARGA_H
#define _CARGA_H

using namespace std;
#include "lista.h"
#include "pelicula.h"

const string ARCHIVO_VISTAS = "peliculas_vistas.txt";
const string ARCHIVO_NO_VISTAS = "peliculas_no_vistas.txt";
const string ARCHIVO_RECOMENDADAS = "peliculas_recomendadas.txt";

class Carga {

    private:

        Lista<Pelicula>* vistas;
        Lista<Pelicula>* no_vistas;
        Lista<Pelicula>* recomendadas;
        string nombre_archivo_vistas = ARCHIVO_VISTAS;
        string nombre_archivo_no_vistas = ARCHIVO_NO_VISTAS;
        string nombre_archivo_recomendadas = ARCHIVO_RECOMENDADAS;

    public:

        /* Constructor Carga
        *  Post: Se inicializa cada atributo de la Carga con su correspondiente parametro recibido.
        */
        Carga(Lista<Pelicula>* vistas, Lista<Pelicula>* no_vistas, Lista<Pelicula>* recomendadas, string archivo_vistas, string archivo_no_vistas, string archivo_recomendadas);

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
        void agregar(Lista<Pelicula>* peliculas, ifstream& archivo);

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
         void leer_pelicula(ifstream &archivo, Pelicula* &peli);
};


#endif //_CARGA_H
