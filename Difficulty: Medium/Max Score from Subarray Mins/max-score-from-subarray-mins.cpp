class Solution {
public:
    int maxSum(vector<int>& arr) {
        int n = arr.size();
        int max_score = 0;

        for (int i = 0; i < n - 1; ++i) {
            int a = arr[i], b = arr[i + 1];
           
            max_score = max(max_score, a + b);

            // Expand to left and right to try to include bigger subarray
           
        }

        return max_score;
    }
};
