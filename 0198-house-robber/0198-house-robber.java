class Solution {
    int n;
    int solve(int[] nums,int i,int sum){
        if(i>=n) return sum;
        int take = solve(nums,i+2,sum+nums[i]);
        int not_take = solve(nums,i+1,sum);
        return Math.max(take,not_take);
    }
    public int rob(int[] nums) {
         n = nums.length;
        return solve(nums,0,0);
    }
}