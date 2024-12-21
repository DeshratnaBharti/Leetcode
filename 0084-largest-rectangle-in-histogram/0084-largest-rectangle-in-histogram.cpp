class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
          int n = heights.size();
    vector<int> stack(n + 1);  // Stack to store indices of the bars
    int index = -1;
    int maxArea = INT_MIN;

    for (int i = 0; i <= n; i++) {
        int element = (i == n) ? 0 : heights[i];  // Set element to 0 for the last iteration
        while (index != -1 && heights[stack[index]] > element) {
            int h = heights[stack[index--]];  // Get the height of the top bar
            int ps = (index == -1) ? -1 : stack[index];  // Get the index of the previous smaller element
            int w = i - ps - 1;  // Calculate width
            maxArea = max(maxArea, h * w);  // Update the maximum area
        }
        stack[++index] = i;  // Push the current index onto the stack
    }
    
    return (maxArea == INT_MIN) ? 0 : maxArea;  
    }
};