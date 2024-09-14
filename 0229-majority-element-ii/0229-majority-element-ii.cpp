class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans;
        unordered_map<int,int>m;
          int mini = int(n / 3) + 1;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        
             if (m[arr[i]] == mini) {
            ans.push_back(arr[i]);}
             if (ans.size() == 2) break;
        }
        return ans;

        
    }
};