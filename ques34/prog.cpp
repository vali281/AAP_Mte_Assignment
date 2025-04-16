// Solution for question 34
// the complexities are :
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefix_sum;
    prefix_sum[0] = 1;
    int sum = 0, count = 0;
    
    for (int num : nums) {
        sum += num;
        if (prefix_sum.find(sum - k) != prefix_sum.end()) {
            count += prefix_sum[sum - k];
        }
        prefix_sum[sum]++;
    }
    
    return count;
}

int main() {
    vector<int> nums = {1, 1, 1};
    int k = 2;
    cout << "Number of subarrays with sum " << k << ": " 
         << subarraySum(nums, k) << endl;
    return 0;
}