class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        sort(strs.begin(), strs.end());

        string first = strs.front();
        string last = strs.back();
        int i = 0;
        string s="";
        while (i < first.size() && first[i] == last[i]) {
            s+=last[i++];
        }

        return s;
    }
};
