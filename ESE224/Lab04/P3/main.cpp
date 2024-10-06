
#include <iostream>
#include <ostream>
#include "TemperatureConversion.h"

using namespace std;

int menu_function(){
    int choice;

    cout << "Select the conversion type:" << endl;
    cout << "1. Celsius to Fahrenheit" << endl;
    cout << "2. Celsius to Kelvin" << endl;
    cout << "3. Fahrenheit to Celsius" << endl;
    cout << "4. Fahrenheit to Kelvin" << endl;
    cout << "5. Kelvin to Celsius" << endl;
    cout << "6. Kelvin to Fahrenheit" << endl;

    cout << "Enter your choice (1-6): ";
    cin >> choice;
    return choice;
}

bool input_valid(int choice_index, float input){
    // kelvin can't be lower than 0K
    // Celius can't be lower than -273.15°C
    // Fahrenheit can't be lower than -459.67°F
    if(choice_index == 1 || choice_index == 2){
        if (input < -273.15){
            return false;
        }
    }
    else if (choice_index == 3 || choice_index == 4) {
        if (input < -459.67){
            return false;
        }
    }
    else if (choice_index == 5 || choice_index == 6) {
        if (input < 0){
            return false;
        }
    }

    return true;
}

string choice_to_input_unit(int index){
    string result;
    if(index == 1 || index == 2){
        result = "Celsius";
    }
    else if (index == 3 || index == 4) {
        result = "Fahrenheit";
    }
    else if (index == 5 || index == 6) {
        result = "Kelvin";
    }
    return result;
}

int main(){

    int choice;
    float input, output;
    string input_unit, output_unit;

    choice = menu_function();
    input_unit = choice_to_input_unit(choice);

    cout << "Enter temperature in " << input_unit << ": ";
    cin >> input;

    // validate input
    if(input_valid(choice, input)){
        // get the output

        if(choice == 1 || choice == 2){
            if(choice == 1){
                output_unit = "Fahrenheit";
                output = celsiusToFahrenheit(input);
            }
            else{
                output_unit = "Kelvin";
                output = celsiusToKelvin(input);
            }
        }
        else if (choice == 3 || choice == 4) {
            if(choice == 3){
                output_unit = "Celsius";
                output = fahrenheitToCelsius(input);
            }
            else{
                output_unit = "Kelvin";
                output = fahrenheitToKelvin(input);
            }
        }
        else if (choice == 5 || choice == 6) {
            if(choice == 5){
                output_unit = "Celsius";
                output = kelvinToCelsius(input);
            }
            else{
                output_unit = "Fahrenheit";
                output = kelvinToFahrenheit(input);
            }
        }

        cout << input << " degrees " << input_unit << " is " << output << " degrees " << output_unit << "." << endl;
    }

    else{
        cout << "Your input is not valid. Conversion can not be made." << endl;
        return 1;
    }

    

    return 0;
}