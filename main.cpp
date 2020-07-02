#include "lista.h"
#include "menu.h"
#include "validacion.h"
#include "pelicula.h"
#include "carga.h"

using namespace std;

const string ARCHIVO_VISTAS = "peliculas_vistas.txt";
const string ARCHIVO_NO_VISTAS = "peliculas_no_vistas.txt";
const string ARCHIVO_RECOMENDADAS = "peliculas_recomendadas.txt";

int main(){
    Lista<Pelicula> peliculas_vistas;
    Lista<Pelicula> peliculas_no_vistas;
    Lista<Pelicula> peliculas_recomendadas;
    Carga carga_peliculas(&peliculas_vistas, &peliculas_no_vistas, &peliculas_recomendadas, ARCHIVO_VISTAS, ARCHIVO_NO_VISTAS, ARCHIVO_RECOMENDADAS);

    carga_peliculas.cargar_datos();

    Validacion validaciones;
    Menu menu(&peliculas_vistas, &peliculas_no_vistas, &peliculas_recomendadas);

    int opcion;
    do{
        menu.mostrar();
        opcion = validaciones.num_entre_rangos("Por favor ingrese una opcion: ", 1, 4);
        cout << " ------------------------------------------------- " << endl;
        menu.mostrar_lista(opcion);
        cout << " ------------------------------------------------- " << endl;
    }while(opcion != 4);

    return 0;
}
