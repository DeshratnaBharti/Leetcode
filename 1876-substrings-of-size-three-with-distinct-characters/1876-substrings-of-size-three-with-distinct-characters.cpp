class Solution {
public:
    int countGoodSubstrings(string s) {
   

    int count = 0;

    // Iterate over the string to consider substrings of size 3
    for (int i = 0; i < s.length() - 2; ++i) {
        // Extract substring of length 3
        string substring = s.substr(i, 3);
        
        // Use a set to check if all characters in the substring are unique
        unordered_set<char> charSet(substring.begin(), substring.end());
        
        // If the size of the set is 3, it means all characters are unique
        if (charSet.size() == 3) {
            ++count;
        }
    }

    return count;

    }
};