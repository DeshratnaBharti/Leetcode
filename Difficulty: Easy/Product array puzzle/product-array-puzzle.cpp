class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>pre;
        vector<int>suff;
        int p=1;
        for(int i=0;i<n;i++){
            p = p * arr[i];
            pre.push_back(p);
        }
        p = 1;
        for(int i = n-1;i>=0;i--){
            p = p *arr[i];
            suff.push_back(p);
        }
      // for(auto a:suff) cout<<a<<" ";
       reverse(suff.begin(),suff.end());
        vector<int>ans(n);
      //  cout<<suff[1];
        ans[0] = suff[1];
        ans[n-1] = pre[n-2];
        //cout<<pre[n-2];
        for(int i=1;i<n-1;i++){
            ans[i]=pre[i-1]*suff[i+1];
            
        }
        return ans;
    }
};
