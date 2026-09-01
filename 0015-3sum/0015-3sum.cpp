class Solution {
public:
    vector<vector<int>>ans;
    void twoSum(vector<int>&nums,int tgt,int i,int j){
        while(i<j){
            if(nums[i] + nums[j] > tgt) j--;
            else if(nums[i] + nums[j] < tgt) i++;
            else{
                while(i<j and nums[i] == nums[i+1]) i++;
                while(i<j and nums[j]== nums[j-1]) j--;
                ans.push_back({-tgt,nums[i],nums[j]});
                i++,j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
       // vecotr<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(i> 0 and nums[i] == nums[i-1]){
                continue;
            }
            int n1= nums[i];
            int tgt = -n1;
            twoSum(nums,tgt,i+1,n-1);
            
        }
        return ans;
        
    }
};