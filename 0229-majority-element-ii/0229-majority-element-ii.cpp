class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        
            if(m[arr[i]] > floor(n/3)) ans.push_back(arr[i]);
        }
        return ans;

        
    }
};