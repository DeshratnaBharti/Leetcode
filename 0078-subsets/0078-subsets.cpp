class Solution {
public:
vector<vector<int>> result;
void solve(int idx,vector<int>& nums,vector<int> temp){
    if(idx==nums.size()){
        result.push_back(temp);
        return;
    }

    solve(idx+1,nums,temp);
  //  temp.pop_back();
     temp.push_back(nums[idx]);

    solve(idx+1,nums,temp);
    

        //temp.push_back(nums[idx]);

}
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<int> temp;//store subset
        solve(0,nums,temp);  
        return result;
    }
};