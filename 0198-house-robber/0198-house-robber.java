import java.util.Arrays;

class Solution {
    int n;
    int[] t;

    int solve(int[] nums, int i) {
        if (i >= n) return 0;
        if (t[i] != -1) return t[i];

        int take = nums[i] + solve(nums, i + 2);
         int notTake = solve(nums, i + 1);

         return t[i]= Math.max(take, notTake);
    }

    public int rob(int[] nums) {
        n = nums.length;
        t = new int[101];
         Arrays.fill(t, -1);
        return solve(nums, 0);
    }
}
