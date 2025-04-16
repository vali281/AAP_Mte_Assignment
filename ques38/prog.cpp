// Solution for question 38
// Time complexity is O(n!)
// Space complexity is O(n) respectively

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generatePermutations(vector<int>& nums, vector<vector<int>>& result, int index) {
    if (index == nums.size()) {
        result.push_back(nums); // Add the current permutation to result
        return;
    }
    
    for (int i = index; i < nums.size(); i++) {
        swap(nums[i], nums[index]); // Swap to generate a new permutation
        generatePermutations(nums, result, index + 1); // Recursive call
        swap(nums[i], nums[index]); // Backtrack
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result;
    
    generatePermutations(nums, result, 0);
    
    cout << "All permutations of the given array are:" << endl;
    for (const auto& permutation : result) {
        cout << "{ ";
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
    
    return 0;
}
