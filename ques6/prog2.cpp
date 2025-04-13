// better approach using 2 pointer and hash
// time and space complexity is O(n) and O(1) respectively
#include <iostream>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;
int Lsub(string s){
    int hash[256] = {-1}; //initialize the values with -1 (the character is not seen yet)
    int maxLen = 0 , L = 0, R =0;
    int n = s.length();
    while(R < n){
        if(hash[s[R]] !=-1){
            if(hash[s[R]] >= L) L = hash[s[R]] + 1; // update L to the next position of the last seen character
        }
        int len = R - L + 1;
        hash[s[R]] = R;
        maxLen = max(maxLen, len);
        R++;
    }
    return maxLen;
}
int main() {
    string s = "abcabcbb";
    cout << "Length of longest unique substring is: " << Lsub(s) << endl;
    return 0;
}