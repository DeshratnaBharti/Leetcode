class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n =nums.size();
        long long count=0;
        for(int i=0;i<n;i++){
            long long s=0;
            for(int j=i;j<n;j++){
                 s+=nums[j];
                 if((s*(j-i+1))<k)count++;
            }
        }
        return count;
    }
};