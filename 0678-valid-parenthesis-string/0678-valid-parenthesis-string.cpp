class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        stack<int>opSt;
        stack<int>starSt;
        for(int i=0;i<n;i++){
            if(s[i]=='(') opSt.push(i);
            else if(s[i]== '*') starSt.push(i);
            else{
                if(!opSt.empty()) opSt.pop();
                else if (!starSt.empty()) starSt.pop();
                else return false;
            }
        }
        while(!opSt.empty() and !starSt.empty()){
            if(opSt.top()>starSt.top()) return false;
            opSt.pop();
            starSt.pop();
        }
        return opSt.empty();

    }
};