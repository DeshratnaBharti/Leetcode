class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
         int n = arr.size();
        vector<int> dp(n, 1), parent(n, -1); // dp[i] stores LIS length ending at i, parent helps reconstruct LIS
    
        // Compute LIS length and track predecessors
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
        }
    
        // Find the index of the maximum LIS length
        int maxLength = 0, index = -1;
        for (int i = 0; i < n; i++) {
            if (dp[i] > maxLength) {
                maxLength = dp[i];
                index = i;
            }
        }
    
        // Reconstruct the LIS sequence
        vector<int> lisSequence;
        while (index != -1) {
            lisSequence.push_back(arr[index]);
            index = parent[index];
        }
    
        reverse(lisSequence.begin(), lisSequence.end()); // Reverse to get correct order
        return lisSequence;
    }
};