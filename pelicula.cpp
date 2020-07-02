#include "pelicula.h"

using namespace std;

Pelicula::Pelicula(string nombre, string genero, int puntaje, string director, Lista<string> actores){
    this->nombre = nombre;
    this->genero = genero;
    this->puntaje = puntaje;
    this->director = director;
    this->actores = actores;
}

Pelicula::~Pelicula(){
}

bool Pelicula::coincide_algun_actor(Lista<string>* actores_comparar){
    int i = 1, j = 1;
    bool coincidencia = false;
    while(!coincidencia && i <= actores.obtener_tam()){
        while(!coincidencia && j <= actores_comparar->obtener_tam()){
            if (actores.obtener_dato(i) == actores.obtener_dato(j))
                coincidencia = true;
            j++;
        }
        i++;
    }
    return coincidencia;
}


bool Pelicula::es_recomendada(Lista<Pelicula>* vistas){
    if(puntaje >= PUNTAJE_MINIMO_RECOMENDADA)
        return true;

    bool es_recomendada = false;
    int i = 1;
    Pelicula aux;
    while(!es_recomendada && i <= vistas->obtener_tam()){
        aux = vistas->obtener_dato(i);
        if(genero == aux.obtener_genero()){
            if( director == aux.obtener_director || coincide_algun_actor(aux.obtener_actores()))
                es_recomendada = true;
        }
        i++;
    }
    return es_recomendada;
}



string Pelicula::obtener_nombre(){
    return nombre;
}
string Pelicula::obtener_genero(){
    return genero;
}
int Pelicula::obtener_puntaje(){
    return puntaje;
}

string Pelicula::obtener_director(){
    return director;
}

Lista<string>* Pelicula::obtener_actores(){
    return &actores;
}


// muestra los atributos de la peli
void Pelicula::mostrar(){
    cout << "soy una pelicula" << endl;
}


