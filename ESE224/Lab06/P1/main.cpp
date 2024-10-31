
#include <iostream>
#include <vector>

using namespace std;

int max_sub_array(vector<int> &nums){

    if(nums.empty()){
        return 0;
    }

    //init for minimum result value
    int result = nums[0] * nums[1];
    int product;

    for(int i = 0 ; i < nums.size() ; i++){
        product = 1;
        for(int j = i ; j < nums.size() ; j++){
            //swap of the product is larger than result
            product *= nums[j];
            if(product > result){
                result = product;
            } 
        }
    }

    return result;

}

int main(){
    vector<int> array = {2, 3, -2, 4};

    cout << "Maximum subarray product: " << max_sub_array(array)<< endl;

    return 0;
}