#include "Arduino.h"
#include "Lineas.h"

Lineas::Lineas(int _pin)
{
    pin = _pin;
        pinMode(pin, INPUT);
}

Lineas::Lineas(int _pin, int _analogico)
{
    analogico = _analogico;
    pinMode(analogico, INPUT);
}

bool Lineas::detectar() //esta funcion detecta si esta obscuro regresara true
{
    valor = digitalRead(pin);
    if(valor == LOW)
    {
        return true;
    }

    else
    {
        return false;
    }
}  

bool Lineas::detectarAn()
{
    valor = analogRead(analogico); //esta funcion detecta brillo y  regresara true
    if(valor < 800)
    {
        return false;
    }
    else
    {
        return true;
    }
}   
