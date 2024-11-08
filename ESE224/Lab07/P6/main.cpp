#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;

// Function to check if two strings are anagrams
bool areAnagrams(const string &str1, const string &str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    unordered_map<char, int> freq;
    // Count characters in the first string
    for (char ch : str1) {
        freq[ch]++;
    }
    // Subtract counts based on the second string
    for (char ch : str2) {
        freq[ch]--;
        if (freq[ch] < 0) {
            return false;
        }
    }
    // Check that all frequencies are zero
    for (const auto &pair : freq) {
        if (pair.second != 0) {
            return false;
        }
    }
    return true;
}

// Function to check if two strings are K-anagrams
bool areKAnagrams(const string &str1, const string &str2, int k) {
    if (str1.length() != str2.length()) {
        return false;
    }

    unordered_map<char, int> freq1, freq2;

    // Count characters in both strings
    for (char ch : str1) {
        freq1[ch]++;
    }
    for (char ch : str2) {
        freq2[ch]++;
    }

    int changesNeeded = 0;
    // Calculate differences in frequencies
    for (const auto &pair : freq1) {
        char ch = pair.first;
        int countInStr1 = pair.second;
        int countInStr2 = freq2[ch];
        if (countInStr1 > countInStr2) {
            changesNeeded += (countInStr1 - countInStr2);
        }
    }

    // If the number of changes needed is within the allowed K, return true
    return changesNeeded <= k;
}

int main() {
    string str1, str2;
    int k;

    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;
    cout << "Enter the value of K: ";
    cin >> k;

    if (areAnagrams(str1, str2)) {
        cout << "The strings are anagrams." << endl;
    } else if (areKAnagrams(str1, str2, k)) {
        cout << "The strings are K-anagrams." << endl;
    } else {
        cout << "The strings are neither anagrams nor K-anagrams." << endl;
    }

    return 0;
}
