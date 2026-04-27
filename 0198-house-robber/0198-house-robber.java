class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        int[] t = new int[n+1];
        t[0] = 0;
        t[1] = nums[0];
        for(int i=2;i<=n;i++){
            int take = nums[i-1]+t[i-2];
            int not_take = t[i-1];
            t[i] = Math.max(take,not_take);
        }
        return t[n];
     }
}