// solving using recursion
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve(vector<int> nums, vector<vector<int>> ans, int index){
    //base case
    if(index >= nums.size()){
        ans.push_back(nums);
        return;
    }
    
}
vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, ans, index);
    return ans;
}