#include "temperatura.h"
#include "mbed.h"
#include <iostream>
#include <cmath>
#include "Grove_LCD_RGB_Backlight.h"
#include <iomanip> // Necessari per a std::setprecision
#include <sstream> // Necessari per a std::ostringstream
#include "temperaturaUser.h"






Grove_LCD_RGB_Backlight lcd(D14,D15);

int main() {
    float tU, t;
    setTemperaturaInicial(calcularTemperatura());
    tU=calcularTemperaturaUsuari();
    
    float tempAnterior=tU;
    
    while (1) {
        tU = calcularTemperaturaUsuari();
        
        t = calcularTemperatura();
        
        std::ostringstream stream;
        stream << "Tem: " << std::fixed << std::setprecision(2) << t << "" << char(0xDF) << "C";
        std::string message = stream.str();
        char output [message.length() + 1];
        strcpy(output, message.c_str());
        
        std::ostringstream stream2;
        stream2 << "TemUser: " << std::fixed << std::setprecision(2) << tU << "" << char(0xDF) << "C";
        std::string mensajeAbajo = stream2.str();
        char outputAbajo[mensajeAbajo.length() + 1];
        strcpy(outputAbajo, mensajeAbajo.c_str());
        

        if(tU>tempAnterior){
            lcd.setRGB(255, 0, 0);  // Color vermell si la temperatura de l'usuari augmenta
        }
        else{
            if(tU<tempAnterior){
                lcd.setRGB(0, 0, 255);  // Color blau si la temperatura de l'usuari disminueix
            }
            else {
                lcd.setRGB(0, 255, 0);  // Color verd si la temperatura de l'usuari es manté igual
            }
        }

        tempAnterior=tU;
        lcd.clear();
        lcd.locate(0, 0);
        lcd.print(output);
        lcd.locate(0, 1);
        lcd.print(outputAbajo);

        ThisThread::sleep_for(1s);
    }
}