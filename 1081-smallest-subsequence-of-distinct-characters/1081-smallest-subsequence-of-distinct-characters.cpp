class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        vector<int> l(26,-1), ta(26,-1);

        string t= "";
        for(int i=0;i<n;i++){
            int a= s[i] - 'a';
            l[a] = i;
        }

        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ta[ch-'a'] != -1) continue;

            while(!t.empty() && t.back() > ch && l[t.back()-'a'] > i){
                char lastChar = t.back();
                t.pop_back();
                ta[lastChar-'a'] = -1;
            }

            t.push_back(ch);
            ta[ch-'a'] = 1;
        }

        return t;
    }
};
