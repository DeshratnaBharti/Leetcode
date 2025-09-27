class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       stack<int>st;
         int n = nums.size();
        vector<int> res(n, -1);
     
        for(int i=n * 2 - 1;i>=0;i--){
             int j = i % n;
            while(!st.empty() and st.top() <= nums[j]){
                st.pop();
            }
             res[j] = (st.empty()) ? -1 : st.top();
            st.push(nums[j]);
            
        } 
        return res;
    }
};