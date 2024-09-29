
#include <iostream>

using namespace std;

int main(){
    
    int arr[] = {10, 20, 30, 40, 50};
    int sum = 0;
    

    cout << "Array element: ";
    for(int num: arr){
        cout << num << " ";
        sum += num;
    }

    cout << endl;
    cout << "Sum of arrray element: " << sum << endl;


    for(int& num: arr){
        num *= 2;
    }

    cout << "New Array element: ";
    for(int num: arr){
        cout << num << " ";
    }


    return 0;
}