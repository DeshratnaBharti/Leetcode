class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st;
        int m = nums1.size();
        int n = nums2.size();
        for(int i=0;i<m;i++){
            st.insert(nums1[i]);

        }
        unordered_set<int>ans;
        for(int i=0;i<n;i++){
            int a = nums2[i];
            if(st.find(a) != st.end()){
                ans.insert(a);
            }
        }
         vector<int>res;
         for(auto a:ans){
            res.push_back(a);
         }
        return res;
        
    }
};