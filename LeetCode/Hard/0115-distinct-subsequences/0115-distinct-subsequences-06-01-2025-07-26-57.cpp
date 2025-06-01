class Solution {
public:
    int f(string &s, string &t, int n, int m, int i, int j) {
        if (j == m) return 1; // Successfully formed subsequence
        if (i == n) return 0; // Exhausted string s but t not formed
        
        if (s[i] == t[j]) {
            return f(s, t, n, m, i+1, j+1) + f(s, t, n, m, i+1, j);
        }
        
        return f(s, t, n, m, i+1, j);
    }
    
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        return f(s, t, n, m, 0, 0);
    }
};
