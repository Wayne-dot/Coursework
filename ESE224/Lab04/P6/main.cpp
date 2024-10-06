
#include <iostream>
#include <string>

using namespace std;

string expand_palindrome(string str, int start, int finish){
    while(start >= 0 && finish < str.length() && str[start] == str[finish]){
        start -=1;
        finish += 1;
    }
    return str.substr(start + 1, finish - start - 1);
}

string longestPalindrome(string str){
    // empty string or 1 character string are palindrome
    if(str.length() <= 1){
        return str;
    }
    
    // set the longest palindrome substring to the first character
    string longest = str.substr(0, 1);
    string even, odd;

    for(int i = 0 ; i < str.length() ; i++){
        // odd palindrome, one center, check for each index, (i), (i+1), (i+2)
        even = expand_palindrome(str, i, i);
        if(even.length() > longest.length()){
            longest = even;
        }

        // even palindrome, two center, check for each i and i + 1, like (1,2) (2,3) (3,4)
        odd = expand_palindrome(str, i, i + 1);
        if(odd.length() > longest.length()){
            longest = odd;
        }
    }

    return longest;

}

int main(){

    string input, output;

    cout << "Enter a string: ";
    cin >> input;

    output = longestPalindrome(input);

    cout << "The longest palindromic substring is " << output << endl;
    return 0;
}