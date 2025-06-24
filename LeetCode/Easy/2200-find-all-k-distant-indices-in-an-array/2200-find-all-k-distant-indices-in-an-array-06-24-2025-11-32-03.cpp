class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> keyIndices;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == key)
                keyIndices.push_back(i);
        }

        set<int> result; // use set to avoid duplicates

        for (int index : keyIndices) {
            int start = max(0, index - k);
            int end = min(n - 1, index + k);

            for (int i = start; i <= end; i++) {
                result.insert(i);
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};
