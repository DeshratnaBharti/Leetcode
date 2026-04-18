class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long n = nums.size();
        long long s = 0,i=0;
        long long maxi = 0;
        unordered_map<int,int>mp;
        
        for(int j=0;j<n;j++){
             s = s + nums[j];
             mp[nums[j]]++;
             if(j-i+1>k){
                 mp[nums[i]]--;
                s = s-nums[i];
                //mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
             }
             if(j-i+1==k and mp.size()==k)
            
              maxi = max(maxi,s);
        }
        return maxi;
    }
};