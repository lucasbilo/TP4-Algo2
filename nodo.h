#ifndef TP4_ALGO2_NODO_H
#define TP4_ALGO2_NODO_H

template < typename Dato >
class Nodo{

private:
    Dato dato; // Dato a almacenar
    Nodo* psig; // Puntero a otro nodo

public:
    // Constructor con parametro
    // PRE: Ninguna
    // POST: Crea un nodo con el dato d y el puntero a NULL
    Nodo(Dato d);

    // Destructor
    // PRE: Nodo creado
    // POST: No hace nada
    ~Nodo();

    // PRE: el nodo tiene que estar creado y d tiene que ser un dato valido
    // POST: dato = d
    void modificar_dato(Dato d);

    // PRE: nodo creado y ps válido
    // POST: psig apuntara a ps
    void modificar_sig(Nodo* ps);

    // PRE: nodo creado
    // POST: devuelve el dato que contiene el nodo
    Dato obtener_dato();

    // PRE: nodo creado
    // POST: Devuelve el puntero al siguiente nodo, si es el último devuelve NULL
    Nodo* obtener_sig();

    // PRE: nodo creado
    // POST: TRUE si psig != NULL. En caso contrario devuelve FALSE
    bool tiene_sig();
};


template < typename Dato >
Nodo<Dato>::Nodo(Dato d){
    dato = d;
    psig = 0;
}

template < typename Dato >
Nodo<Dato>::~Nodo(){

}

template < typename Dato >
void Nodo<Dato>::modificar_dato(Dato d){
    dato = d;
}

template < typename Dato >
void Nodo<Dato>::modificar_sig(Nodo* ps){
    psig = ps;
}

template < typename Dato >
Dato Nodo<Dato>::obtener_dato(){
    return dato;
}

template < typename Dato >
Nodo<Dato>* Nodo<Dato>::obtener_sig(){
    return psig;
}

template < typename Dato >
bool Nodo<Dato>::tiene_sig(){
    return (psig != 0);
}


#endif //TP4_ALGO2_NODO_H
