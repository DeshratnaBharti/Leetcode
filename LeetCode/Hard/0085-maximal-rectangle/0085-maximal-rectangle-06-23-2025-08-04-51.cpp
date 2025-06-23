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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m = matrix[0].size();
         if(n==0) return 0;
      
         vector<int> nums(m);
        int largest =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val = matrix[i][j]-'0';
                if(val == 0) nums[j] =0;
                else nums[j]+= val;
            }
            int maxArea = largestRectangleArea(nums);
            if(largest<maxArea) largest = maxArea;
        }
        return largest;
    }
};