class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
            
                // Calculate the amount of water
                int amount = min(arr[i], arr[j]) * (j - i);
            
                // Keep track of maximum amount of water
                res = max(amount, res);
            }
        }
        return res;
}

};