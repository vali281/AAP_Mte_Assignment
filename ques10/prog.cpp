// Time complexity is O(n * n!) 
// Space complexity is O(n) respectively

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int>& nums, vector<vector<int>>& ans, int index) {
    // Base case: If we have reached the end, add the current permutation to the result
    if (index == nums.size()) {
        ans.push_back(nums);
        return;
    }

    // Recursively generate permutations by swapping each element with the current element
    for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);  // Swap the current index with i
        solve(nums, ans, index + 1);  // Recurse with the next index
        swap(nums[index], nums[i]);  // Backtrack and undo the swap
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, ans, index);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> permutations = permute(nums);

    cout << "All permutations: " << endl;
    for (const auto& perm : permutations) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
