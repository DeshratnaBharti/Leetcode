class Solution {
public:
    int f(char &c) {
        if (c == 'I') return 1;
        else if (c == 'V') return 5;
        else if (c == 'X') return 10;
        else if (c == 'L') return 50;
        else if (c == 'C') return 100;
        else if (c == 'D') return 500;
        else return 1000;
    }

    int romanToDecimal(string &s) {
        int res = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            int R1 = f(s[i]);
            if (i + 1 < n) {
                int R2 = f(s[i + 1]);
                if (R1 < R2) {
                    res += (R2 - R1);
                    i++; // skip next character
                } else {
                    res += R1;
                }
            } else {
                res += R1;
            }
        }
        return res;
    }
};
