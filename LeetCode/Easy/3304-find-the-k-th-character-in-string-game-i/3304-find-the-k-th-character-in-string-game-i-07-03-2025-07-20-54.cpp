class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while (word.length() < k) {
            string temp = word;
            for (int i = 0; i < word.length(); i++) {
                if (word[i] == 'z') word[i] = 'a';
                else word[i] = word[i] + 1;
            }
            word = temp + word;
        }
        return word[k - 1];
    }
};
