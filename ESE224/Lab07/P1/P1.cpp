

#include <iostream>

using namespace std;

void reverseArray(int* arr, int size){
    int *ptr_start = arr;
    int *ptr_end = arr + size - 1;
    int temp;

    while(ptr_start < ptr_end){
        temp = *ptr_start;
        *ptr_start = *ptr_end;
        *ptr_end = temp;

        ptr_start++;
        ptr_end--;
    }
}

int main(){

    int arr[] = {10, 20, 30,40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    int *ptr = arr;

    reverseArray(arr, size);

    cout << "Array elements are: ";

    for(int i = 0 ; i < size ; i++){
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    return 0;
}