class Solution {
public:
    void solve(int idx,   vector<int>&temp,vector<vector<int>>&result,int sum,int k,int n){
        if(sum==n and k==0){
            result.push_back(temp);
            return;
        }
        if(sum>n) return;
        if(k<0) return;
        for(int i=idx;i<=9;i++){
            if(i>n) break;
            temp.push_back(i);
            solve(i+1,temp,result,sum+i,k-1,n);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<vector<int>>result;
       vector<int>temp;
       solve(1,temp,result,0,k,n);
        return result;
        
    }
};