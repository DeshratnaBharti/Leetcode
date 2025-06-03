class Solution {
public:
    
    bool isMatchHelper(const string &s, const string &p, int i, int j) {
        if (j == p.size()) return i == s.size(); // Pattern exhausted
        
        if (i < s.size() && (s[i] == p[j] || p[j] == '?'))
            return isMatchHelper(s, p, i+1, j+1); // Match single character
        
        if (p[j] == '*')
            return isMatchHelper(s, p, i, j+1) || (i < s.size() && isMatchHelper(s, p, i+1, j)); // '*' matches any sequence

        return false; // No match
    }
    bool isMatch(string s, string p) {
        return isMatchHelper(s, p, 0, 0);
    }
};