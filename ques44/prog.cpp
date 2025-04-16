// Solution for question 44
// Time complexity is O(n)
// Space complexity is O(n) respectively

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool findTwoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> seen;
    
    for (int num : nums) {
        int complement = target - num;
        if (seen.find(complement) != seen.end()) {
            cout << "Pair found: (" << complement << ", " << num << ")" << endl;
            return true;
        }
        seen[num] = 1;
    }
    
    return false;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    if (!findTwoSum(nums, target)) {
        cout << "No pair found that adds up to the target." << endl;
    }
    
    return 0;
}
