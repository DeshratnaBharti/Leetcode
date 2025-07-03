class Solution {
public:
    
    void findlps(const string& pat, vector<int>& lps, int M) {
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while (i < M) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }


    bool kmp(const string& txt, const string& pat) {
        int N = txt.length();
        int M = pat.length();
        vector<int> lps(M, 0);
        findlps(pat, lps, M);

        int i = 0, j = 0;
        while (i < N) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }

            if (j == M) {
                return true; // Match found
            } else if (i < N && txt[i] != pat[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false; 
    }

  
    int repeatedStringMatch(string a, string b) {
        if (a == b) return 1;

        int repeat = 1;
        string temp = a;

        while (temp.size() < b.size()) {
            temp += a;
            repeat++;
        }

        if (kmp(temp, b)) return repeat;
        if (kmp(temp + a, b)) return repeat + 1;

        return -1;
    }
};
