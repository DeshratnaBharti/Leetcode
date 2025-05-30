class Solution {
public:
    int helper(string &word1, string &word2, int i, int j, vector<vector<int>> &memo) {
       
        if (i < 0) return j + 1;  // Remaining characters in word2
        if (j < 0) return i + 1;  // Remaining characters in word1
        
        // Check if the result is already computed
        if (memo[i][j] != -1) return memo[i][j];

        // If characters match, move diagonally without any operation
        if (word1[i] == word2[j]) {
            return memo[i][j] = helper(word1, word2, i - 1, j - 1, memo);
        }

        // Perform min operation (insert, delete, replace)
        int insertOp = helper(word1, word2, i, j - 1, memo); // Insert in word1
        int deleteOp = helper(word1, word2, i - 1, j, memo); // Delete from word1
        int replaceOp = helper(word1, word2, i - 1, j - 1, memo); // Replace
        
        return memo[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
    }
    int minDistance(string word1, string word2) {
        int length1 = word1.size();
        int length2 = word2.size();
        vector<vector<int>> memo(length1, vector<int>(length2, -1)); // Memoization table
        return helper(word1, word2, length1 - 1, length2 - 1, memo);
    }


};
