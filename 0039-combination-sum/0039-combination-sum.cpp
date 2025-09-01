class Solution {
public:
   void solve(int idx,vector<vector<int>> &result, vector<int>&temp,vector<int>& candidates, int target){
    
        if(target== 0){
            result.push_back(temp);
            return;
        }
       if(target<0 )  return;
       if(idx==candidates.size()) return;
         
           temp.push_back(candidates[idx]);
       solve(idx,result,temp,candidates,target-candidates[idx]);
       temp.pop_back();
       solve(idx+1,result,temp,candidates,target);
       
   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> temp;//store subset
    vector<vector<int>> result;
    //sort(nums.begin(),nums.end());
         solve(0,result,temp,candidates,target);
        return result;      
}
    
};