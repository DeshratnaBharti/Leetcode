class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
        string filtered;

    // Step 1: Remove non-alphanumeric characters and convert to lowercase
    for (char ch : s) {
        if (isalnum(ch)) {
            filtered += tolower(ch);
        }
    }

    // Step 2: Check if filtered string is a palindrome
    int left = 0, right = filtered.size() - 1;
    while (left < right) {
        if (filtered[left] != filtered[right])
            return false;
        left++;
        right--;
    }

    return true;
    }
};