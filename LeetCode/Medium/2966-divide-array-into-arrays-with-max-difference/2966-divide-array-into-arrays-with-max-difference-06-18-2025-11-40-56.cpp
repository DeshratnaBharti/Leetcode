class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % 3 != 0) return {}; // Can't divide into groups of 3

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n; i += 3) {
            vector<int> temp;
            for (int j = i; j < i + 3; ++j) {
                temp.push_back(nums[j]);
            }

            // Only need to compare max and min in sorted group
            if (temp[2] - temp[0] > k) return {};
            ans.push_back(temp);
        }

        return ans;
    }
};
