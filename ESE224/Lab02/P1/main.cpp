
#include "Box.h"
#include <iostream>

using namespace std;

int main(){
    Box box1(5, 6, 7);
    Box box2(3, 4, 5);

    Box box3 = box1 + box2;
    Box box4 = box1 - box2;

    cout << "Resulting box after addition: ";
    box3.display();

    cout << "Resulting box after subtraction: ";
    box4.display();


    return 0;
}