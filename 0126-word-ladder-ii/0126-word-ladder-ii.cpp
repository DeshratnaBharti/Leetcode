class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return {}; // Ensure endWord is in wordList

        unordered_map<string, vector<string>> parents; // Store predecessors
        unordered_set<string> visited, currentLevelVisited; // Mark visited nodes
        queue<string> que;
        que.push(beginWord);
        bool found = false;

        while (!que.empty() && !found) {
            int n = que.size();
            currentLevelVisited.clear();

            for (int i = 0; i < n; ++i) {
                string word = que.front();
                que.pop();

                for (int j = 0; j < word.size(); ++j) {
                    string temp = word;
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        temp[j] = ch;

                        if (dict.find(temp) != dict.end() && visited.find(temp) == visited.end()) {
                            currentLevelVisited.insert(temp);
                            parents[temp].push_back(word); // Record the predecessor
                            que.push(temp);

                            if (temp == endWord) found = true;
                        }
                    }
                }
            }
            visited.insert(currentLevelVisited.begin(), currentLevelVisited.end()); // Mark words in current level as visited
        }

        // Backtracking to construct all paths
        vector<vector<string>> result;
        vector<string> path;
        if (found) {
            backtrack(endWord, beginWord, parents, path, result);
        }

        return result;
    }

private:
    void backtrack(const string& word, const string& beginWord, 
                   unordered_map<string, vector<string>>& parents, 
                   vector<string>& path, vector<vector<string>>& result) {
        path.push_back(word);
        if (word == beginWord) {
            result.push_back(vector<string>(path.rbegin(), path.rend())); // Reverse path
        } else {
            for (const auto& parent : parents[word]) {
                backtrack(parent, beginWord, parents, path, result);
            }
        }
        path.pop_back();
    }
};
