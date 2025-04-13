// better approach
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
string palin(string s){
    int n = s.length();
    int r, l, maxlen = 0, start = 0;
    for(int i =0; i < n; i++){
        // for odd length string
        r = i, l = i;
        while(r < n && l >= 0 && s[l] == s[r]){
            if(s[r] == s[l]){
                int len = r - l + 1;
                if(len > maxlen){
                    maxlen = len;
                    start = l;
                }
                r++;
                l--;
            }
        }
        // for even length string
        r = i, l = i + 1;
        while(r < n && l >= 0 && s[l] == s[r]){
            if(s[r] == s[l]){
                int len = r - l + 1;
                if(len > maxlen){
                    maxlen = len;
                    start = l;
                }
                r++;
                l--;
            }
        }
    }
    return s.substr(start, maxlen); // return longest palindrome
    
}
int main(){
    string s = "babadcdabab";
    cout << "Longest Palindromic Substring: " << palin(s) << endl;
    return 0;
}