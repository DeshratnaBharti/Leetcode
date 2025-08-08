class Solution {
  public:
    int getLPSLength(string &s) {
        int n = s.length();
        vector<int> lps(n, 0);

        int length = 0;
        int i = 1;  // Start from index 1

        while (i < n) {
            if (s[i] == s[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps[n - 1];  // Last value is the LPS length
    }
};
