class Solution {
public:
    bool rotateString(string s, string t) {
       queue<char>q1,q2;
        if(s==t) return true;
        for(int i=0;i<s.size();i++){
            q1.push(s[i]);
        }
        for(int j=0;j<t.size();j++){
            q2.push(t[j]);
        }
        int k = t.size()-1;
        while(k--){
            char ch = q2.front();
            q2.pop();
            q2.push(ch);
            if(q1==q2) return true;
        }
        return false;
    }
};