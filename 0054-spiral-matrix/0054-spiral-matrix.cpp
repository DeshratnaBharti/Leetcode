class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        int minr = 0, minc = 0; // Minimum row and column
        int maxr = m - 1, maxc = n - 1; // Maximum row and column

        vector<int> ans; // Result array to store spiral order

        while (minr <= maxr && minc <= maxc) {
            // Traverse from left to right (Top Row)
            for (int j = minc; j <= maxc; j++) {
                ans.push_back(arr[minr][j]);
            }
            minr++; // Move top boundary down

            // Traverse from top to bottom (Right Column)
            for (int i = minr; i <= maxr; i++) {
                ans.push_back(arr[i][maxc]);
            }
            maxc--; // Move right boundary left

            // Check if there is still a valid bottom row
            if (minr <= maxr) {
                // Traverse from right to left (Bottom Row)
                for (int j = maxc; j >= minc; j--) {
                    ans.push_back(arr[maxr][j]);
                }
                maxr--; // Move bottom boundary up
            }

            // Check if there is still a valid left column
            if (minc <= maxc) {
                // Traverse from bottom to top (Left Column)
                for (int i = maxr; i >= minr; i--) {
                    ans.push_back(arr[i][minc]);
                }
                minc++; // Move left boundary right
            }
        }

        return ans; // Return the spiral order
    }
};
