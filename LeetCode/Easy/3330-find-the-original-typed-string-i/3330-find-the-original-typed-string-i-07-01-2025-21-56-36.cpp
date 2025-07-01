class Solution {
public:
    int possibleStringCount(string word) {
        int count = 1;  // The original string is always valid
        for (int i = 1; i < word.length(); ++i) {
            if (word[i] == word[i - 1]) {
                count++;  // Removing one repeated character gives a new possibility
            }
        }
        return count;
    }
};
