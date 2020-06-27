#include "lista.h"
#include "menu.h"
#include "validacion.h"
#include "pelicula.h"

using namespace std;

int main(){
    Lista<Pelicula> peliculas_vistas;
    // cargar pelis leidas
    Lista<Pelicula> peliculas_no_vistas;
    // cargar pelis NO vistas
    Lista<Pelicula> peliculas_recomendadas;
    // cargar esta lista con las peliculas correspondientes

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
