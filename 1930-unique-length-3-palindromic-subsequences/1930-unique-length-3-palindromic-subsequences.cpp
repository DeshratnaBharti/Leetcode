class Solution {
public:
    int countPalindromicSubsequence(string s) {
         vector<int> leftCount(26, 0);     // To keep track of left side characters
    vector<int> rightCount(26, 0);    // To keep track of right side characters

    // Initial right count
    for (char c : s) {
        rightCount[c - 'a']++;
    }

    unordered_set<string> uniquePalindromes; // To store unique palindromes

    // Traverse through the string treating every character as the middle
    for (char middle : s) {
        int middleCharIndex = middle - 'a';

        // Remove current middle character from right count
        rightCount[middleCharIndex]--;

        // Check for palindromes with this middle character
        for (int leftCharIndex = 0; leftCharIndex < 26; leftCharIndex++) {
            if (leftCount[leftCharIndex] > 0 && rightCount[leftCharIndex] > 0) {
                // Correctly create the palindrome
                string palindrome = "";
                palindrome += (char)(leftCharIndex + 'a'); // Convert to char
                palindrome += middle;                     // Add middle character
                palindrome += (char)(leftCharIndex + 'a'); // Convert to char
                uniquePalindromes.insert(palindrome);
            }
        }

        // Add the current middle character to left count
        leftCount[middleCharIndex]++;
    }

    return uniquePalindromes.size();
    }
};