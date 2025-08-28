class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0; // Position to write compressed output
        int i = 0;

        while (i < n) {
            char ch = chars[i];
            int count = 0;

            // Count how many times ch repeats
            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }

            // Write character
            chars[write++] = ch;

            // Write count if more than 1
            if (count > 1) {
                string s = to_string(count);
                for (char c : s) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};
