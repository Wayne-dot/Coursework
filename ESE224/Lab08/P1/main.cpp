
#include <iostream>

using namespace std;

int find_min(int *arr, int size){
    int min = arr[0];
    
    for(int i = 0 ; i < size ; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }

    return min;
}

int find_max(int *arr, int size){
    int max = arr[0];
    
    for(int i = 0 ; i < size ; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}


int main(){
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];

    if(!arr){
        cout << "Memory allocation failed" << endl;
        return 1;
    }

    cout << "Enter " << size << " integers\n";
    for(int i = 0 ; i < size ; i++){
        cout << "Element " << i+1 << ": ";
        cin >> arr[i];
    }

    int sum = 0;
    for(int i = 0 ; i < size ; i++){
        sum += arr[i];
    }

    double average = static_cast<double>(sum) / size;

    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Minimum is " << find_min(arr, size) << endl;
    cout << "Maximum is " << find_max(arr, size) << endl;


    delete[] arr;
    cout << "Memory freed. Program ending" << endl;

    return 0;
}