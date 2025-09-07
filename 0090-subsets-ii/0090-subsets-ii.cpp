class Solution {
public:
   
void solve(int idx,vector<int>& nums,vector<int> &temp,vector<vector<int>>& result){
   
        result.push_back(temp);

    
    for(int i=idx;i<nums.size();i++){
        if(i != idx and nums[i] == nums[i-1]) continue;
        temp.push_back(nums[i]);
        solve(i+1,nums,temp,result);
        temp.pop_back();
    } 
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  vector<int> temp;//store subset
    vector<vector<int>> result;
    sort(nums.begin(),nums.end());
    solve(0,nums,temp,result);  
        return result;      
 }
};