#include "validacion.h"
#include <iostream>
using namespace std;

int Validacion::num_entre_rangos(string mensaje, int min, int max){
    int num;
    cout << mensaje;
    cin >> num;
    while((num < min) || (num > max)){
        cout << "Numero ingresado fuera de rango, vuelva a intentarlo: ";
        cin >> num;
    }
    return num;
}

