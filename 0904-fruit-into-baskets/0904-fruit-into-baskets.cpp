class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int maxlen = 0;int l =0 ,r=0;
        int k=2;
        while(r<arr.size()){
            mp[arr[r]]++;
            if(mp.size()>k){
                while(mp.size()>k){
                    mp[arr[l]]--;
                    if(mp[arr[l]]==0) mp.erase(arr[l]);
                    l++;
                }
            }
            if(mp.size()<=k) maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};