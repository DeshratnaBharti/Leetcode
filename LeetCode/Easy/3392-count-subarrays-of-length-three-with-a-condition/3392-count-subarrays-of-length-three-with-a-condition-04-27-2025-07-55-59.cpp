class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        // Ensuring that we only process valid subarrays of size exactly 3
        for (int i = 0; i <= n - 3; i++) {  
            for(int j=i;j<n;j++){
                if (j-i+1==3 and 2*(nums[i] + nums[j]) == nums[i+1]) {  
                    count++;
                }
            }
        }

        return count;
    }
};
