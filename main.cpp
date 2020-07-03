#include "menu.h"
#include "validacion.h"
#include "carga.h"

using namespace std;

int main(){
    Lista<Pelicula> peliculas_vistas;
    Lista<Pelicula> peliculas_no_vistas;
    Lista<Pelicula> peliculas_recomendadas;
    Carga carga_peliculas(&peliculas_vistas, &peliculas_no_vistas, &peliculas_recomendadas);

    carga_peliculas.cargar_datos();

    Validacion validaciones;
    Menu menu(&peliculas_vistas, &peliculas_no_vistas, &peliculas_recomendadas);

    int opcion;
    do{
        menu.mostrar();
        opcion = validaciones.num_entre_rangos("Por favor ingrese una opcion: ", 1, 4);
        cout << " ------------------------------------------------- " << endl;
        menu.ir_a_opcion(opcion);
        cout << " ------------------------------------------------- " << endl;
    }while(opcion != 4);

    return 0;

}
