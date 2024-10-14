
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

using namespace std;

// n = 1, first occurence
// n = 2, last occurence
int Occurence(int arr[], int size, int target, int n){
    int left = 0, right = size - 1, result = -1, mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if(arr[mid] == target){
            result = mid;
            if(n == 1){
                right = mid - 1;
            }
            else if (n == 2) {
                left = mid + 1;
            }
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return result;
}

int main(){
    ifstream InputFile("input.txt");

    if(!InputFile){
        cerr << "File can not be open" << endl;
        return 1;
    }

    string line;
    int size, num, target, firstIndex, lastIndex;

    while(getline(InputFile, line)){
        stringstream ss(line);
        ss >> size;
        int arr[size];

        cout << "Array: ";
        
        for(int i = 0 ; i < size ; i++){
            ss >> num;
            arr[i] = num;
            cout << num << " ";
        }
        cout << endl;

        ss >> target;
        cout << "Target: " << target << endl;

        // n = 1, first occurence
        // n = 2, last occurence
        firstIndex = Occurence(arr, size, target, 1);
        lastIndex = Occurence(arr, size, target, 2);

        cout << "First occurrence of " << target << " is at index: " << firstIndex << endl;
        cout << "Last occurrence of " << target << " is at index: " << lastIndex << endl;

        cout << "--------------------" << endl; 
    }

    

    return 0;
}