class Solution {
public:
    
      vector<int> findNSE(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSEE(vector<int>& nums) {
        int n = nums.size();
        vector<int> psee(n);
        stack<int> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }
    int largestRectangleArea(vector<int>& nums) {
        int n= nums.size();
         vector<int> nse = findNSE(nums);
        vector<int> psee = findPSEE(nums);
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            int height = nums[i];
            int width =  nse[i] -  psee[i]-1;
            maxi = max(maxi,(height*width));
        }
         return maxi;
        
    }
};