class Solution {
public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        int n = arr.size();
        long long s = 0, maxi = 0;
        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++){
            s += arr[i];

            int rem = (s % k + k) % k; 

            if(rem == 0){
                maxi = i + 1;
            }
            else if(mp.find(rem) != mp.end()){
                maxi = max(maxi,(long long) i - mp[rem]);
            }

            if(mp.find(rem) == mp.end()){
                mp[rem] = i;
            }
        }
        return maxi;
    }
};