// Solution for question 40
// Time complexity is O(n)
// Space complexity is O(n) respectively

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int findMaxFrequencyElement(const vector<int>& nums) {
    unordered_map<int, int> freqMap;
    int maxFreq = 0;
    int maxElem = -1;
    
    // Store the frequency of each element
    for (int num : nums) {
        freqMap[num]++;
    }
    
    // Find the element with the maximum frequency
    for (const auto& entry : freqMap) {
        if (entry.second > maxFreq) {
            maxFreq = entry.second;
            maxElem = entry.first;
        }
    }
    
    return maxElem;
}

int main() {
    vector<int> nums = {1, 2, 3, 1, 2, 1};
    
    cout << "Element with maximum frequency: " << findMaxFrequencyElement(nums) << endl;
    
    return 0;
}
