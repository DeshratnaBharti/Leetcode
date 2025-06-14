class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        if (n < 2) return 0; // A bitonic sequence must have both increasing and decreasing parts

        // Step 1: Compute LIS ending at each index
        vector<int> LIS(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }

        // Step 2: Compute LDS starting at each index
        vector<int> LDS(n, 1);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[i]) {
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }

        // Step 3: Compute the maximum bitonic subsequence length
        int max_length = 0;
        for (int i = 0; i < n; i++) {
            if (LIS[i] > 1 && LDS[i] > 1) { // Ensure both increasing and decreasing parts exist
                max_length = max(max_length, LIS[i] + LDS[i] - 1);
            }
        }

        return max_length;
    }
};
