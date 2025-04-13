// Brute force approach to find longest palindromic substring
// time and space complexity is O(n^3) and O(1) respectively
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// Checks if a substring is palindrome
bool isPalindrome(string s, int start, int end){
    while(start <= end){
        if(s[start] != s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
string Lpalindrome(string s){
    int n = s.length();
    int maxLen = 0;
    int startIndex = 0;
    for(int start = 0; start < n; start++){
        for(int end = start; end < n; end++){
            if(isPalindrome(s, start, end)){
                int len = end - start + 1;
                if(len > maxLen){
                    maxLen = len;
                    startIndex = start;
                }
            }
        }
    }
    return s.substr(startIndex, maxLen); // return longest palindrome
}

int main(){
    string s = "babadcdabad";
    // to check if the string is palindrome or not 
    // if(isPalindrome(s , 0 , 6)){
    //     cout << "Yes, the string palindrome" << endl;
    // }
    // else{
    //     cout << "NO, the string is not palindrome" << endl;
    // }
    cout << "Longest Palindromic Substring: " << Lpalindrome(s) << endl;
    return 0;
}
