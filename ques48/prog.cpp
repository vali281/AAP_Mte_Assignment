// Solution for question 48
// Time complexity is O(n)
// Space complexity is O(1) respectively

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    // Step 1: Find the first decreasing element from the end
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        int j = n - 1;

        // Step 2: Find the element just larger than nums[i]
        while (nums[j] <= nums[i]) {
            j--;
        }

        // Step 3: Swap nums[i] and nums[j]
        swap(nums[i], nums[j]);
    }

    // Step 4: Reverse the elements after the position i
    reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    vector<int> nums = {1, 2, 3};
    
    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    nextPermutation(nums);

    cout << "Next permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
