class Solution {
public:
    int lengthOfLongestSubstring(string t) {
        set<char>s;
        int maxi =0;
        int start =0;int end =0;
        while(start<t.length()){
            auto ch = s.find(t[start]);
            if(ch == s.end()){
                if(start -end +1 > maxi) maxi = start-end+1;
                s.insert(t[start]);
                start++;
            }
            else{
                s.erase(t[end]);
                end++;
            }
        }
        return maxi;
    }
};