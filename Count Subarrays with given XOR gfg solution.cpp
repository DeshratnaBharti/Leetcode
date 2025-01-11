
long subarrayXor(vector<int> &arr, int k) {
unordered_map<int,int>mp;
        int n = arr.size();
        long ans =0, prefXor=0;
        for(int i=0;i<n;i++){
            prefXor = prefXor ^arr[i];
            ans += mp[prefXor ^ k] + (prefXor ==k);
            mp[prefXor]++;
        }
        return ans;
    }
