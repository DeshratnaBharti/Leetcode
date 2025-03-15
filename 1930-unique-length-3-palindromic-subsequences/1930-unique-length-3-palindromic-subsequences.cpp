class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        int result = 0;

        // Har ek letter ('a' se 'z') ke liye check karo
        for (char letter = 'a'; letter <= 'z'; letter++) {
            int left_idx = -1, right_idx = -1;

            // Leftmost aur rightmost position dhundo
            for (int i = 0; i < n; i++) {
                if (s[i] == letter) {
                    if (left_idx == -1) left_idx = i; // Pehla 'letter'
                    right_idx = i; // Last 'letter'
                }
            }

            // Agar dono sides hai (left aur right index valid hain)
            if (left_idx != -1 && right_idx != -1 && left_idx < right_idx) {
                unordered_set<char> middleCharacters;

                // Beech wale unique characters ko store karo
                for (int middle = left_idx + 1; middle < right_idx; middle++) {
                    middleCharacters.insert(s[middle]);
                }

                // Unique middle characters ka size count karo
                result += middleCharacters.size();
            }
        }

        return result;
    }
};
