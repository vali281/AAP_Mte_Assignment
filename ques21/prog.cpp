// Solution for question 21
// Time Complexity: O(n log n)
// Space Complexity: O(1) [excluding output array], O(n) [including output]

#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int n) {
    vector<int> result(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        result[i] = result[i & (i - 1)] + 1;
    }
    return result;
}

int main() {
    int n = 5;
    vector<int> ans = countBits(n);
    cout << "Count of 1's for numbers 0 to " << n << ":\n";
    for (int i = 0; i <= n; ++i) {
        cout << i << ": " << ans[i] << "\n";
    }
    return 0;
}