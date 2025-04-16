// Solution for question 35
// the complexities are :
// Time Complexity: O(n log k)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    // Count frequencies
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    
    // Min-heap to keep top k elements
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Loop through each key-value pair in the frequency map
    for (unordered_map<int, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
        pq.push({it->second, it->first}); // {count, num}
        if (pq.size() > k) {
            pq.pop();
        }
    }
    
    // Extract results
    vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    
    return result;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);
    
    cout << "Top " << k << " frequent elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
