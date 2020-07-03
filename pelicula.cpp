#include "pelicula.h"

using namespace std;

Pelicula::Pelicula(){
}

Pelicula::Pelicula(string nombre, string genero, int puntaje, string director, Lista<string>* actores){
    this->nombre = nombre;
    this->genero = genero;
    this->puntaje = puntaje;
    this->director = director;
    this->actores = actores;
}

Pelicula::~Pelicula(){
    delete actores;
}

void Pelicula::copiar_pelicula(Pelicula* original){
    nombre = original->obtener_nombre();
    genero = original->obtener_genero();
    puntaje = original->obtener_puntaje();
    director = original->obtener_director();
    actores = new Lista<string>;
    actores->copiar(original->obtener_actores());
}

bool Pelicula::coincide_algun_actor(Lista<string>* actores_comparar){
    for(unsigned i = 1; i <= actores->obtener_tam(); i++){
        for(unsigned j = 1; j <= actores_comparar->obtener_tam(); j++){
            if (*actores->obtener_dato(i) == *actores->obtener_dato(j))
                return true;
        }
    }
    return false;
}


bool Pelicula::es_recomendada(Lista<Pelicula>* vistas){
    if(puntaje >= PUNTAJE_MINIMO_RECOMENDADA)
        return true;
    if(!vistas->lista_vacia()){
        for(unsigned i = 1; i < vistas->obtener_tam(); i++) {
            if(genero == vistas->obtener_dato(i)->obtener_genero()){
                if( director == vistas->obtener_dato(i)->obtener_director() || coincide_algun_actor(vistas->obtener_dato(i)->obtener_actores()))
                    return true;
            }
        }
    }
    return false;
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
    return actores;
}


void Pelicula::mostrar_actores(){
    cout << "Actores: ";
    for(unsigned i = 1; i <= actores->obtener_tam(); i++){
        cout << *actores->obtener_dato(i) << " ";
    }
    cout << "\n";
}

// muestra los atributos de la peli
void Pelicula::mostrar(){
    cout << "Nombre:" << nombre  << endl;
    cout << "Genero: " << genero << endl;
    cout << "Puntaje: " << puntaje << endl;
    cout << "Director: " << director << endl;
    mostrar_actores();
}

