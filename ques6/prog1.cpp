// solution using brute force
// time and space complexity is O(n^2) and O(1) respectively
#include <iostream>
using namespace std;
int Lsub(string s){
    int maxLen = 0;
    for(int i = 0; i < s.length(); i++){
        int hash[256] = {0}; // Initializes all values to 0
        for(int j = i; j < s.length(); j++){
            if(hash[s[j]] == 1){
                break; // If the character is already seen, break the loop
            }
            int len = j -i + 1;
            maxLen = max(maxLen, len);
            hash[s[j]] = 1;
        }
    }
    return maxLen;

}
int main() {
    string s = "abcabcbb";
    cout << "Length of longest unique substring is: " << Lsub(s) << endl;
    return 0;
}