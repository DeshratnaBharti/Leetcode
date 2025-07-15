class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) return false;

        bool hasVowel = false;
        bool hasConsonant = false;

        for (char c : word) {
            if (!isalnum(c)) return false;

            if (isalpha(c)) {
                if (isVowel(c)) hasVowel = true;
                else hasConsonant = true;
            }
        }

        return hasVowel && hasConsonant;
    }

private:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
