class Solution {
public:
    string removeKdigits(string arr, int k) {
        if(k>= arr.length()) return "0";
        int n = arr.length();
        stack<char>st;
        for(int i=0 ;i<n;i++){
            if(st.empty() ) st.push(arr[i]);
            else{
                while(!st.empty()and  st.top()>arr[i] and k>0){
                    st.pop();
                    k--;
                }
                st.push(arr[i]);
            }
        }
         while( k>0){
            st.pop();
            k--;
        }
        
        if(st.empty()) return "0";
        string ans="";
        while(!st.empty()){
            ans += (st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
       
     int i=0;
        while(ans[i]=='0'){
            i++;
        }
       return (ans.substr(i)=="") ? "0" : ans.substr(i);
    }
};