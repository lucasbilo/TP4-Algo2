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
        Carga(Lista<Pelicula>* vistas, Lista<Pelicula>* no_vistas, Lista<Pelicula>* recomendadas,
              std::string archivo_vistas, std::string archivo_no_vistas, std::string archivo_recomendadas);
        ~Carga();
        void cargar_datos();

    private:
        void agregar(Lista<Pelicula>* peliculas, std::ifstream& archivo);
        void agregar_recomendadas();
        Pelicula leer_pelicula(std::ifstream &archivo);
};


#endif //_CARGA_H
