class Solution {
public:
vector<vector<int>> result;
void solve(int idx,vector<int>& nums,vector<int> &temp){
   
        result.push_back(temp);

    
    for(int i=idx;i<nums.size();i++){

    temp.push_back(nums[i]);
    solve(i+1,nums,temp);
     temp.pop_back();
    } 
}
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<int> temp;//store subset
        solve(0,nums,temp);  
        return result;
    }
};