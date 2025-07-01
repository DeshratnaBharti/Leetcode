class Solution {
public:
    int minAddToMakeValid(string s) {
        int o=0,c=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') o++;
            else c++;
        }
        return abs(o-c);
    }
};