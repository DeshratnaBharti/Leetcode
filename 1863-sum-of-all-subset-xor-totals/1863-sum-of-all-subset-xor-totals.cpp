class Solution {
public:
    vector<vector<int>> subset;
    int n;

    // Function to calculate the XOR sum of all subsets
    int xorsum() {
        int sum = 0;
        for (const auto& s : subset) {
            int Xor = 0;
            for (int num : s) {
                Xor ^= num;
            }
            sum += Xor;
        }
        return sum;
    }

    // Recursive function to generate subsets
    void sub(vector<int>& nums, vector<int>& ans, int i) {
        if (i == n) {
            subset.push_back(ans);
            return;
        }
        // Exclude current element
        sub(nums, ans, i + 1);
        // Include current element
        ans.push_back(nums[i]);
        sub(nums, ans, i + 1);
        ans.pop_back(); // Remove the last added element
    }

    // Main function to calculate the XOR sum
    int subsetXORSum(vector<int>& nums) {
        n = nums.size();
        vector<int> ans;
        sub(nums, ans, 0);
        return xorsum();
    }
};
