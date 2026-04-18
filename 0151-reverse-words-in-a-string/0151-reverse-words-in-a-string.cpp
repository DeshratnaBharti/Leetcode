class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string w,ans = "";
        while(ss>>w){
            ans = w + " "+ ans;
        }
        while(!ans.empty() and ans.back()==' ')ans.pop_back();
        return ans;
    }
};