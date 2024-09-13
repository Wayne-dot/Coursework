// Practice01.cpp : This file contains the 'main' function. Program execution begins and ends there.


//OOP notes

#include <iostream>

using namespace std;

class MyClass {
    private:
        int y;
        int myNum;
        string myString;
    public:
        void newMethod();

        MyClass (string name, int x) {
            myNum = x;
            cout << "You create a Object!\n";
        }

        void myMethod() {
            cout << "This printout method\n";
        }
    
};

//To declear constructor outside of class
//MyClass::MyClass(int x) {
//  myNum = x;
//}

// To declear method outside of class
void MyClass::newMethod() {
    cout << "This printout newMethod string";
}


class Vechicle {
    public:
        string brand = "Ford";
        void honk() {
            cout << "Honk Honk";
        }
};

class Car : public Vechicle {
    protected:
        int custom = 5;
    public:
        void hook() {
            cout << "Car honk honk" << endl;
        }
        string model = "Mustang";
};

class MyOtherClass: public Car, public Vechicle {
    public:
        void myOtherFunction() {
            cout << "My other function\n" << custom << endl;
        }
};

int main()
{
    MyClass myObj("John", 5);

    //myObj.myNum = 5;
    //myObj.myString = "This is a string";

    //myObj.myMethod();

    //cout << myObj.myNum << endl;
    int x;
    cin >> x;

    cout << "Hello World!\nYou Input number: " << x << endl;

    return 0;
}
