// Solution for question 36
// Time complexity is O(2^n)
// Space complexity is O(n) respectively

#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(vector<int>& nums, vector<int>& current, int index) {
    // Print current subset
    cout << "{ ";
    for (int i : current) {
        cout << i << " ";
    }
    cout << "}" << endl;

    // Generate further subsets
    for (int i = index; i < nums.size(); i++) {
        current.push_back(nums[i]);
        generateSubsets(nums, current, i + 1);
        current.pop_back();  // Backtrack
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> current;
    
    cout << "Subsets of the given array are:" << endl;
    generateSubsets(nums, current, 0);
    
    return 0;
}
