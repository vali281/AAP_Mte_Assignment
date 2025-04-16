// Solution for question 37
// Time complexity is O(2^n)
// Space complexity is O(target) respectively

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findCombinations(vector<int>& candidates, vector<vector<int>>& result, vector<int>& current, int target, int start) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    
    for (int i = start; i < candidates.size(); i++) {
        if (i > start && candidates[i] == candidates[i - 1]) continue; // Skip duplicates
        if (candidates[i] > target) break; // No need to continue if the current number exceeds target
        
        current.push_back(candidates[i]);
        findCombinations(candidates, result, current, target - candidates[i], i + 1); // move to the next index
        current.pop_back(); // backtrack
    }
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result;
    vector<int> current;
    
    sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
    
    findCombinations(candidates, result, current, target, 0);
    
    cout << "Unique combinations that sum to " << target << " are:" << endl;
    for (const auto& combination : result) {
        cout << "{ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
    
    return 0;
}
