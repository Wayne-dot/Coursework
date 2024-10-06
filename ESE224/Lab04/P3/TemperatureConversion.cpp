
#include "TemperatureConversion.h"

float celsiusToFahrenheit(float celsius){
    return (9*celsius/5) + 32;
}

float celsiusToKelvin(float celsius){
    return celsius+ 273.15;
}
float fahrenheitToCelsius(float fahrenheit){
    return (fahrenheit - 32)*5/9;
}
float fahrenheitToKelvin(float fahrenheit){
    return ((fahrenheit - 32)*5/9) + 273.15;
}
float kelvinToCelsius(float kelvin){
    return kelvin- 273.15;
}
float kelvinToFahrenheit(float kelvin){
    return ((kelvin - 273.15)*9/5) + 32;
}