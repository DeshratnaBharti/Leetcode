class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>map;
        stack<int>st;
        int n = nums2.size();
        for(int i =n-1;i>=0;i--){
            int ele = nums2[i];
            while(!st.empty() and st.top() <= ele){
                st.pop();
            }
            int res = (st.empty()) ? -1 : st.top();
            map.insert({ele,res});
            st.push(ele);
            
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(map[nums1[i]]);
        }
        return ans;
    }
};