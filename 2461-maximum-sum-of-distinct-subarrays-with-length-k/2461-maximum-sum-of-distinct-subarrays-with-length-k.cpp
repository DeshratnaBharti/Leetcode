class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long n = nums.size();
        long long s = 0,i=0;
        long long maxi = 0;
        unordered_set<int>st;
        
        for(int j=0;j<n;j++){
             s = s + nums[j];
             st.insert(nums[j]);
             if(j-i+1>k){
                 
                s = s-nums[i];
                //mp[nums[i]]--;
                 st.erase(nums[i]);
                i++;
             }
             if(j-i+1==k and st.size()==k)
            
              maxi = max(maxi,s);
        }
        return maxi;
    }
};