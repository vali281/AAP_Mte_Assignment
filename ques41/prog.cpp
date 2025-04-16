// Solution for question 41
// Time complexity is O(n)
// Space complexity is O(1) respectively

#include <iostream>
#include <vector>
using namespace std;

int maxSubArraySum(const vector<int>& nums) {
    int maxSum = nums[0];
    int currentSum = nums[0];
    
    for (int i = 1; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]); // Kadane's step
        maxSum = max(maxSum, currentSum); // Update maximum sum
    }
    
    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    cout << "Maximum subarray sum using Kadane's algorithm: " << maxSubArraySum(nums) << endl;
    
    return 0;
}
