class Solution {
public:
    string removeOuterParentheses(string s) {
        int count =0;
        string result = "";
        for(int i=0;i<s.length();i++){
            if(s[i] == ')') count--;
            if(count != 0) result.push_back(s[i]);
            if(s[i] == '(') count++;
        }
        return result;
    }
};