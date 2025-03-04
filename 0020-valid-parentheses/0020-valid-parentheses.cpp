class Solution {
public:
    bool isValid(string s) {
       stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' or s[i]=='{' or s[i] =='[') st.push(s[i]);
            else if(s[i]==')'){
                if(st.empty() or st.top() !='(') return false;
                st.pop();
            }
             else if(s[i]=='}'){
                if(st.empty() or st.top() !='{') return false;
                st.pop();
            } 
            else if(s[i]==']'){
                if(st.empty() or st.top() !='[') return false;
                st.pop();
            }
        }
         return st.empty();
    }
};