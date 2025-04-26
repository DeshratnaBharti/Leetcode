

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> mp;
        for (char c : t) mp[c]++;  // Count occurrences of each character in t
        
        int left = 0, right = 0, minLen = INT_MAX, start = 0;
        int countReq = t.size();  // Total required characters
        string result = "";

        while (right < s.size()) {
            if (mp[s[right]] > 0) countReq--;
            mp[s[right]]--;  // Decrease frequency of seen character
            right++;

            while (countReq == 0) { // If all characters from t are covered
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                mp[s[left]]++;  // Move left pointer to minimize window
                if (mp[s[left]] > 0) countReq++;
                left++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

