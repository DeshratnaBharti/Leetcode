#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int globalMax = INT_MIN; // Store the overall maximum
        
        for (int rotation = 0; rotation < n; ++rotation) {
            // Rotate the array by shifting elements
            rotateArray(nums);
            
            // Apply Kadane's Algorithm to the rotated array
            int currMax = INT_MIN, currSum = 0;
            for (int i = 0; i < n; ++i) {
                currSum += nums[i];
                currMax = max(currMax, currSum);
                if (currSum < 0) currSum = 0; // Reset if sum becomes negative
            }
            
            globalMax = max(globalMax, currMax); // Update global maximum
        }
        
        return globalMax;
    }
    
private:
    void rotateArray(vector<int>& nums) {
        int n = nums.size();
        int temp = nums[0]; // Store the first element
        for (int i = 1; i < n; ++i) {
            nums[i - 1] = nums[i]; // Shift elements left
        }
        nums[n - 1] = temp; // Put the first element at the end
    }
};
