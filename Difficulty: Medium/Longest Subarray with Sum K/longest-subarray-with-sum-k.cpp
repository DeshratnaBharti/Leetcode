class Solution {
  public:
    int longestSubarray(vector<int>& arr, int t) {
        // code here
         int n = arr.size();
        int i=0,j=0,s=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int maxi =0;
        while(j<n){
            s = s + arr[j];
            if(!mp.empty() and mp.find(s-t)!=mp.end()){
                 maxi = max(maxi,j-mp[s-t]);
            }
            if(mp.find(s) == mp.end()){  
                mp[s] = j;
            }
            j++;
        }
        return maxi;
    }
};