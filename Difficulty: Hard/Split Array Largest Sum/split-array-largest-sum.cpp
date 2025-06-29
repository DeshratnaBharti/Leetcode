class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n= nums.size();
        int l =0,h=0,mid,ans;
        for(int i=0;i<n;i++){
            l=max(l,nums[i]);
            h+= nums[i];
        }
        while(l<=h){
            mid = l + (h-l)/2;
            int subarray =0, count = 1;
            for(int i=0;i<n;i++){
                subarray += nums[i];
                if(subarray > mid){
                    count++;
                    subarray = nums[i];
                }
            }
            if(count <= k) {
                ans = mid;
                h=mid-1;
                
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};