class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int i = 0, j = 0; // Use separate indices for both strings

        // Alternate characters from both strings
        while (i < word1.length() && j < word2.length()) {
            ans += word1[i++];
            ans += word2[j++];
        }

        // Append the remaining characters from the longer string
        while (i < word1.length()) {
            ans += word1[i++];
        }

        while (j < word2.length()) {
            ans += word2[j++];
        }

        return ans;
    }
};