class Solution {
public:
    int ladderLength(string bW, string eW, vector<string>& wordL) {
        unordered_set<string> dict(wordL.begin(), wordL.end());
        if (dict.find(eW) == dict.end()) return 0; // Ensure endWord is in wordList

        queue<string> que;
        que.push(bW);
        int level = 1;

        while (!que.empty()) {
            int n = que.size();
            while (n--) {
                string curr = que.front();
                que.pop();
                if (curr == eW) return level;

                for (int j = 0; j < curr.size(); j++) {
                    char ch = curr[j];
                    for (int k = 0; k < 26; k++) {
                        curr[j] = 'a' + k;
                        if (dict.find(curr) != dict.end()) {
                            que.push(curr);
                            dict.erase(curr); // Remove to prevent revisiting
                        }
                    }
                    curr[j] = ch; // Restore original character
                }
            }
            level++;
        }
        return 0;
    }
};
