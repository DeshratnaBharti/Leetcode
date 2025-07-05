class Solution {
public:
    int maxSum(vector<int>& arr) {
        int n = arr.size();
        int max_score = 0;

        for (int i = 0; i < n - 1; ++i) {
            int a = arr[i], b = arr[i + 1];
            int min1 = min(a, b), min2 = max(a, b);
            max_score = max(max_score, min1 + min2);

            // Expand to left and right to try to include bigger subarray
            int l = i - 1, r = i + 2;
            while (l >= 0 && r < n) {
                int x = arr[l], y = arr[r];

                // Only expand if both elements are ≥ min2
                if (x >= min2 && y >= min2) {
                    max_score = max(max_score, min1 + min2);
                    l--;
                    r++;
                } else {
                    break;
                }
            }
        }

        return max_score;
    }
};
