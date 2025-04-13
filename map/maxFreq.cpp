#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;
int mapping(int arr[] , int n){
    unordered_map<int, int> count;
    int maxFreq = 0;
    int maxAns = 0;
    for(int i = 0; i < n; i++){
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }
    int maxi = INT_MIN;
    int ans = -1;
    for(auto i : count){
        if(maxFreq == count[arr[i]]){
            maxAns = arr[i];
            break;
        }
    }
    return ans;

}