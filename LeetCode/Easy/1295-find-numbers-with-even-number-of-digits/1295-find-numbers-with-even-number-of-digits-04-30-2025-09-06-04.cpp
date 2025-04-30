class Solution {
public:
    bool isValid(int n) {
        return ((int)log10(n) + 1) % 2 == 0;  // Count digits using log10
    }

    int findNumbers(vector<int>& nums) {
        int evenCount = 0;
        for (int num : nums) {
            if (isValid(num)) evenCount++;
        }
        return evenCount;
    }
};
