#include "carga.h"
#include <string>
#include <fstream>

using namespace std;

Carga::Carga(Lista<Pelicula>* vistas, Lista<Pelicula>* no_vistas, Lista<Pelicula>* recomendadas,
        string archivo_vistas, string archivo_no_vistas, string archivo_recomendadas){

    this->vistas = vistas;
    this->no_vistas = no_vistas;
    this->recomendadas = recomendadas;
    this->nombre_archivo_vistas = archivo_vistas;
    this->nombre_archivo_no_vistas = archivo_no_vistas;
    this->nombre_archivo_recomendadas = archivo_recomendadas;
}

Carga::~Carga(){
}

Pelicula Carga::leer_pelicula(ifstream &archivo){
    string nombre, genero, director, actor_aux, puntaje_str, linea_en_blanco;
    Lista<string>* actores = new Lista<string>;
    int puntaje;
    getline(archivo, nombre);
    getline(archivo, genero);
    getline(archivo, puntaje_str);
    puntaje = stoi(puntaje_str);
    getline(archivo, director);
    archivo >> actor_aux;
    actores->insertar(actor_aux);
    while(archivo.get() == ' '){
        archivo >> actor_aux;
        actores->insertar(actor_aux);
    }
    getline(archivo, linea_en_blanco);
    return Pelicula(nombre, genero, puntaje, director, actores);
}

void Carga::agregar(Lista<Pelicula>* peliculas, ifstream& archivo){

    Pelicula* aux;
    while(!archivo.eof()){
        *aux = leer_pelicula(archivo);
        peliculas->insertar(*aux);
    }
}

void Carga::agregar_recomendadas(){
    Pelicula* aux;
    for(int i = 1; i <= no_vistas->obtener_tam(); i++){
        if(no_vistas->obtener_dato(i).es_recomendada(vistas))
            aux->copiar_pelicula(no_vistas->obtener_dato(i));
            recomendadas->insertar(*aux);
    }
}

void Carga::cargar_datos(){

    ifstream archivo_vistas(nombre_archivo_vistas);
    ifstream archivo_no_vistas(nombre_archivo_no_vistas);
    ifstream archivo_recomendadas(nombre_archivo_recomendadas);
    if(!archivo_vistas.fail()){
        agregar(vistas, archivo_vistas);
        archivo_vistas.close();
    }
    if(!archivo_vistas.fail()){
        agregar(no_vistas, archivo_no_vistas);
        archivo_no_vistas.close();
        agregar_recomendadas();
    }else{
        //hay que tirar un excepcion
    }
}