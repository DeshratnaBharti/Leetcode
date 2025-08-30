class Solution {
public:
    string minWindow(string s, string p) {
        if (p.length() > s.length()) return "";

        vector<int> need(128, 0), window(128, 0);
        for (char ch : p) need[ch]++;

        int required = 0;
        for (int i = 0; i < 128; i++)
            if (need[i] > 0) required++;

        int formed = 0, left = 0, minLen = INT_MAX, start = -1;

        for (int right = 0; right < s.length(); right++) {
            char ch = s[right];
            window[ch]++;
            if (window[ch] == need[ch]) formed++;

            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char remove = s[left];
                window[remove]--;
                if (window[remove] < need[remove]) formed--;
                left++;
            }
        }

        return (start == -1) ? "" : s.substr(start, minLen);
    
    }
};