

#include <stdio.h>
#include <math.h>

// float(*op)(float)

float integral(float left, float right, int k,  float (*op)(float)){
    float val = (right - left) / k;
    float sum = 0;
    for(int i = 0 ; i < k ; i++){
        sum += ((op(left) + op(left+val))*val)/2;
        left += val;
    }
    return sum;
} 

// cubic cannot be found on math.h
float cubic(float x){
    return x * x * x;
}

int main(){
    // initlize parameter
    float left = 4.0, right = 30.0;
    int k = 6;

    // square root, ln, exponential, square and cubic
    // output the value
    printf("Square root = %f\n", integral(left, right, k, sqrtf));
    printf("Ln = %f\n", integral(left, right, k, logf));
    printf("Exponential (e^x) = %f\n", integral(left, right, k, expf));
    printf("Cubic = %f\n", integral(left, right, k, cubic));
    return 0;
}