class Solution {
public:
    int characterReplacement(string arr, int k) {
      int  mp[26]={0};
         int maxF =0;
        int maxlen = 0;int l =0 ,r=0;
       
        while(r<arr.size()){
            mp[arr[r]-'A']++;
            maxF = max(maxF, mp[arr[r]-'A']);
            
                while((r-l+1) -maxF>k){
                    mp[arr[l]-'A']--;
                    maxF =0;
                   
                    l++;
                }
            
            if((r-l+1) -maxF<=k) maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};