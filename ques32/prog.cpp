// Time complexity is O(n)
// Space complexity is O(n) respectively

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    int n = heights.size();
    
    // Traverse through each bar in the histogram
    for (int i = 0; i < n; i++) {
        // While the current bar is smaller than the bar at top of stack, pop from stack
        while (!s.empty() && heights[s.top()] > heights[i]) {
            int height = heights[s.top()];
            s.pop();
            // Calculate the width of the rectangle
            int width = (s.empty()) ? i : i - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        s.push(i); // Push the current bar index onto the stack
    }
    
    // Process the remaining bars in the stack
    while (!s.empty()) {
        int height = heights[s.top()];
        s.pop();
        int width = (s.empty()) ? n : n - s.top() - 1;
        maxArea = max(maxArea, height * width);
    }
    
    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    
    cout << "The largest rectangle area in the histogram is: " << largestRectangleArea(heights) << endl;
    
    return 0;
}
