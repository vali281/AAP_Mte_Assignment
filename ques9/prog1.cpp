// solving using brute force
// time and space complexity is O(n^2) and O(1) respectively
#include <iostream>
using namespace std;
string Lpre(string arr[], int n){
    string ans = "";
    // traversing all characters of the first string
    for(int i = 0; i < arr[0].size(); i++){
        char ch = arr[0][i];
        bool match = true;
        // check if the character is present in all the strings
        for(int j = 1; j < n; j++){
            if(arr[j][i] !=ch || arr[j].size() < i){
                match = false;
                break;
            }
        }
        if(match == false) break;
        else{
            ans.push_back(ch); // add the character to the answer
        }
    }
    return ans;
}
void testCase(string arr[], int n) {
    string result = Lpre(arr, n);
    if (result.length() > 0)
        cout << "Longest Common Prefix: \"" << result << "\"" << endl;
    else
        cout << "No Common Prefix found." << endl;
}
int main() {
    string arr1[] = {"flower", "flow", "flight"};
    cout << "Test Case 1:\n";
    testCase(arr1, 3);
    string arr2[] = {"dog", "racecar", "car"};
    cout << "\nTest Case 2:\n";
    testCase(arr2, 3);
    string arr3[] = {"interspecies", "interstellar", "interstate"};
    cout << "\nTest Case 3:\n";
    testCase(arr3, 3);
    return 0;
}