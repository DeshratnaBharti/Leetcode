#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string change(const string &s) { // Pass by const reference to avoid unnecessary copies
        string result;
        for (char ch : s) {
            if (ch == 'z') {
                result += "ab"; // Replace 'z' with "ab"
            } else {
                result += (char)(ch + 1); // Shift character forward
            }
        }
        return result;
    }

    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1000000007;
        
        for (int i = 0; i < t; i++) {
            s = change(s); // Apply transformation iteratively
        }

        return s.length() % MOD; // Return length mod 10^9 + 7
    }
};

