class Solution {
public:
        int longestSubsequence(string s, int k) {
        int answer = 0;         // Used to track the length of the longest subsequence
        int value = 0;          // Used to store the current value of the binary subsequence
        // Loop through the string backwards to consider the least significant bits first
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                // If the current character is '0', we can always include it without
                // affecting the value of the binary number it represents.
                ++answer;
            } else if (answer < 30 && (value | (1 << answer)) <= k) {
                // Check if the current length of the subsequence is less than 30
                // (Because 2^30 is the first number larger than 10^9, which is outside the constraint for k)
                // and if by setting the current bit to 1 we still get a value less than or equal to k.
                // 1 << answer is the value of setting the current bit (at position 'answer') to 1.
                value |= 1 << answer;  // Set the current bit to 1.
                ++answer;              // Increment the length of the longest subsequence.
            }
            // If the bit is '1' and including it would make the value exceed k or
            // the length of the subsequence is already equal or longer than 30, skip it.
        }
        return answer;
        }
};