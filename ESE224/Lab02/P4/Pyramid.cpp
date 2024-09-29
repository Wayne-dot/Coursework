
#include "Pyramid.h"
#include <iostream>
#include <ostream>

using namespace std;

Pyramid::Pyramid(int he): height(he){

}

void Pyramid::create(){

    // Notes about pattern of printing space and X
    // height = 4
    // 3-1-3
    // 2-3-2
    // 1-5-1
    // 0-7-0
    
    for(int i = 0 ; i < height ; i++){
        for(int j = height - 1 - i; j > 0 ; j--){
            cout << " ";
        }
        for(int k = 1 ; k <= (2 * i) + 1 ; k ++){
            cout << "X";
        }
        for(int w = height - 1 - i ; w > 0 ; w--){
            cout << " ";
        }
        cout << endl;
    }

    cout << endl;
}

void Pyramid::flip(){
    for(int i = 0 ; i < height ; i++){
        for(int j = 0; j < i ; j++){
            cout << " ";
        }
        for(int k = 0 ; k < 2*(height - i - 1) + 1; k++){
            cout << "X";
        }
        for(int w = 0; w < i ; w++){
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}