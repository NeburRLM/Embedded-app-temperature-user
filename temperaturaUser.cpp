#include "temperatura.h"
#include <cmath>
#include "mbed.h"
#include <iostream>

float temperaturaUser;


float ultimaLecturaValida = 0.0;  // Emmagatzema l'última lectura vàlida

float calcularTemperaturaUsuari() {
    AnalogIn angleUser(A1);
    float lectura = angleUser.read();

    // Verifica si hi ha un canvi significatiu en la lectura actual
    if (fabs(lectura - ultimaLecturaValida) > 0.01) {
        ultimaLecturaValida = lectura;
    }

    float temperatura = (ultimaLecturaValida - 0.5) * 10;

    float res = temperaturaUser + temperatura;
    return res;
}



void setTemperaturaInicial(float t){
    temperaturaUser= t;
}



