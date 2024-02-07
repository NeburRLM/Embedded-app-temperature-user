#ifndef TEMPERATURA_USER_H
#define TEMPERATURA_USER_H

#include "mbed.h"

extern float temperaturaUser;  // Declaración de la variable global
extern float ultimaLecturaValida;  // Declaración de la variable global

float calcularTemperaturaUsuari();
void setTemperaturaInicial(float t);

#endif