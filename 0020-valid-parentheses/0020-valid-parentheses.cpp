class Solution {
public:
    bool isValid(string s) {
       stack<char>st;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(s[i]=='(' or s[i]=='{' or s[i] =='[') st.push(s[i]);
            else {
                if(!st.empty() and  ch ==')' and  st.top() =='(') 
                st.pop();
           
           else  if(!st.empty() and  ch =='}' and  st.top() =='{') 
                st.pop();
            
           else if(!st.empty() and ch ==']' and  st.top() =='[') 
                st.pop();
            else return false;    

        }
        }
         return st.empty();
    }
};