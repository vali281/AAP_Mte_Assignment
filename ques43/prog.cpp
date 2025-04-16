// Solution for question 43
// Time complexity is O(n log k)
// Space complexity is O(n) respectively

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topKFrequent(const vector<int>& nums, int k) {
    unordered_map<int, int> freqMap;
    
    // Step 1: Count the frequency of each element
    for (int num : nums) {
        freqMap[num]++;
    }

    // Step 2: Use a min-heap (priority queue) to store the k most frequent elements
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    
    for (const auto& entry : freqMap) {
        minHeap.push({entry.second, entry.first});
        if (minHeap.size() > k) {
            minHeap.pop();  // Ensure the heap only contains the top K elements
        }
    }

    // Step 3: Extract the elements from the heap
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    
    return result;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    
    vector<int> result = topKFrequent(nums, k);
    
    cout << "Top " << k << " frequent elements are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
