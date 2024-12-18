

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
         vector<int>ans;
        stack<int>st;
        for(int i=0;i<n;i++){
               
                    while(!st.empty() and arr[i] <0 and st.top()>0){
                        int sum = arr[i] + st.top();
                        if(sum<0) st.pop();
                        else if(sum > 0) arr[i]=0;
                        else {
                            st.pop();
                            arr[i]=0;
                        }
                       
                    }
            if(arr[i] !=0) st.push(arr[i]);
            }
        
        
        while(st.size()>0){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};