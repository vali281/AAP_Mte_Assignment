// Solution for question 31
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dq; // Stores indices of array elements in decreasing order
    
    for (int i = 0; i < nums.size(); ++i) {
        // Remove elements that are out of the current window
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }
        
        // Remove elements smaller than the current element from the back of the deque
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        
        // Add the current element's index to the deque
        dq.push_back(i);
        
        // Once we have processed the first k elements, the front of the deque holds the maximum element for the current window
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    
    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    
    vector<int> max_values = maxSlidingWindow(nums, k);
    
    cout << "Maximum values in each sliding window of size " << k << ": ";
    for (int val : max_values) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
