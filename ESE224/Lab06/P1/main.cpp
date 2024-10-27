
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> nums = {2, 3, -2, 4};

    int temp, max_product = nums[0]* nums[1];

    for(int i = 0 ; i < nums.size() ; i++){
        for(int j = i ; j < nums.size() - 1 ; j++){
            temp = nums[i] * nums[j+1];
            if(temp > max_product){
                max_product = temp;
            }
        }
    }
    cout << max_product << endl;

    return 0;
}