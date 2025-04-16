// Solution for question 23
// the complexities are :
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int findMaximumXOR(vector<int>& nums) {
    int max_xor = 0, mask = 0;
    
    for (int i = 31; i >= 0; --i) {
        mask |= (1 << i);
        unordered_set<int> prefixes;
        
        for (int num : nums) {
            prefixes.insert(num & mask);
        }
        
        int candidate = max_xor | (1 << i);
        for (int prefix : prefixes) {
            if (prefixes.count(candidate ^ prefix)) {
                max_xor = candidate;
                break;
            }
        }
    }
    return max_xor;
}

int main() {
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << "Maximum XOR: " << findMaximumXOR(nums) << endl;
    return 0;
}