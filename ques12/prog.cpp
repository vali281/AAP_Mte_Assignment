// the complexities are :
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    // Step 1: Find the first index 'i' from the end where nums[i] < nums[i + 1]
    while (i >= 0 && nums[i] >= nums[i + 1])
        i--;

    if (i >= 0) {
        // Step 2: Find the first index 'j' from the end where nums[j] > nums[i]
        int j = n - 1;
        while (nums[j] <= nums[i])
            j--;
        swap(nums[i], nums[j]);
    }

    // Step 3: Reverse the subarray from i+1 to end
    reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    vector<int> nums = {1, 2, 3};
    nextPermutation(nums);

    cout << "Next permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
