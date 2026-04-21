class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            int a = arr[i];
            while(st.size()>0 and st.top()<=a){
                st.pop();
            }
            if(st.size()==0){
                ans[i]=-1;
            }else{
                ans[i] = st.top();
            }
            st.push(a);
        }
        return ans;
    }
};