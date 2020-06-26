#ifndef TP4_ALGO2_VALIDACION_H
#define TP4_ALGO2_VALIDACION_H

// Este objeto esta destinado a tener metodos que sean validaciones.
#include <string>

class Validacion{

public:
    //Constructor
    // POST: Inicializa al objeto.
    Validacion(){};

    // PRE: max >= min // mensaje sera mostrado al usuario
    // POST: Pide al usuario un numero entero. Si el numero ingresado no esta entre los rangos,
    // se lo vuelve a pedir, y así sucesivamente..
    // Devuelve el numero ingresado por el usuario (el que esta entre los rangos pasados por parametro)
    int num_entre_rangos(std::string mensaje, int min, int max);

};

#endif //TP4_ALGO2_VALIDACION_H
