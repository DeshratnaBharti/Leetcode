class Solution {
public:
    string reverseWords(string s) {
        stack<char>st;
        int n = s.length();
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch==' '){
                 if (!st.empty() && st.top() != '$')
                    st.push('$');
            }
           // st.push('$');
            else st.push(s[i]);
        }
        string finalAns = "",t ="";
        while(!st.empty()){
            char ch = st.top();
            st.pop();
           
           if(ch == '$'){
               if(!t.empty()){
                 reverse(t.begin(),t.end());
                 finalAns += t + " ";
                 t = "";
               }
            }
            if(ch!='$')t = t + ch;

        }
        if(!t.empty()){
            reverse(t.begin(),t.end());
            finalAns += t;
        }
        return finalAns;
        
    }
};