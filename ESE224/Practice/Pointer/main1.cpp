
#include <cstddef>
#include <iostream>
#include <string>
#include <utility>


//static keyword
//224 Chapter 6, 52



using namespace std;

int x = 4;

//pass by reference function
void swap(double& x, double& y){
    double temp = x;
    x = y;
    y = temp;
}

int main(){
    int x = 5;

    cout << "memory adress of x is " << &x << endl;

    int *Px = &x;
    int y = *Px;

    cout << "The value of y is " << y << endl;

    char str[] = "example";
    char *s = NULL;

    int z = 100, *xp, *ip;
    xp = &z;
    ip = xp;

    cout << *ip << endl;

    char myString[] = "This is a string";
    char *string;
    string = myString;

    for(int i = 0 ; string[i] ; i++){
        cout << string[i];
    }
    cout << endl;


    cout << "Global scope for x is " << ::x << endl;
 

    return 0;
}

void a(){
    int x = 23;
    x++;
}


void b(){
    //this change the global scope of x
    x++;
}




// int q=6;
// int *iPtr = &q;

// cout << "iPtr is " << iPtr << endl;
// cout << "*iPtr is " << *iPtr << endl;
// cout << "++*iPtr, is " << ++*iPtr << endl;
// cout << "q is " << q << endl;
// cout << "iPtr is " << iPtr << endl;
// cout << "*iPtr++ is " << *iPtr++ << endl;

// cout << "iPtr is " << iPtr << endl;
// cout << "q is " << q << endl;


// 0x7fff2f14
// 6
// 7
// 7
// 0x7fff2f14
// 7
// 0x7fff2f18
// 7







// char myString[] = "This is a string";
// char *strPtr;
// strPtr = myString;
// cout << *myString << endl;
// cout<<myString << endl;

// cout << *(myString + 1) << endl;

// strPtr++;
// cout << *++strPtr << endl;
// myString++;





// T
// This is a string
// h
// i


The keyword static in C++ modifies the behavior and lifetime of a variable, function, or class member depending on its context. Here’s an explanation of how it affects variables and functions in various contexts:

1. static for Variables in Functions

A static variable inside a function has the following properties:
	•	Lifetime: It persists for the entire duration of the program, meaning its value is retained between function calls.
	•	Scope: It remains local to the function, so it cannot be accessed outside of the function.

Example:

void exampleFunction() {
    static int counter = 0; // Initialized only once
    counter++;
    std::cout << "Counter: " << counter << std::endl;
}

int main() {
    exampleFunction(); // Output: Counter: 1
    exampleFunction(); // Output: Counter: 2
    exampleFunction(); // Output: Counter: 3
    return 0;
}

Here, the counter variable retains its value across multiple calls to exampleFunction() because it is static.

2. static for Global Variables

A static global variable restricts its scope to the file where it is declared. This means:
	•	It cannot be accessed from other files in the same program.
	•	This is used to prevent name conflicts in large programs with multiple files.

Example:

static int x = 42; // Accessible only in this file

3. static for Class Members

A static member of a class has the following properties:
	•	Shared among all objects: There is only one instance of a static member, shared by all objects of the class.
	•	Accessed without an instance: It can be accessed using the class name (e.g., ClassName::staticMember).
	•	Lifetime: It exists for the entire lifetime of the program.

Example:

class MyClass {
public:
    static int counter; // Declaration
    static void incrementCounter() { counter++; }
};

int MyClass::counter = 0; // Definition

int main() {
    MyClass::incrementCounter();
    MyClass::incrementCounter();
    std::cout << "Counter: " << MyClass::counter << std::endl; // Output: Counter: 2
    return 0;
}

4. static for Functions

A static function at the global or file scope has the following properties:
	•	File scope only: It can only be called from within the file where it is defined. This makes it inaccessible to other files.
	•	Used for encapsulation of helper functions within a file.

Example:

static void helperFunction() {
    std::cout << "This is a helper function." << std::endl;
}

Here, helperFunction() is only accessible within the file it is defined in.

Summary of static Keyword Behavior:

Context	Effect
Function Variable	Persistent value between function calls, local scope.
Global Variable	Restricts access to the file it is declared in.
Class Member	Shared among all objects of the class, accessible via the class name.
Function (Global)	Restricts function access to the file it is declared in.

In short, static is useful for controlling variable lifetimes, sharing data between objects, and limiting scope for encapsulation.