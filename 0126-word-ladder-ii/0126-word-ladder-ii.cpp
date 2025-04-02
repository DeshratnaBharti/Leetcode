class Solution {
public:
     void dfs(const string& word, const string& beginWord, 
             unordered_map<string, vector<string>>& parents, 
             vector<string>& path, vector<vector<string>>& result) {
        path.push_back(word);
        if (word == beginWord) {
            result.push_back(vector<string>(path.rbegin(), path.rend()));
        } else {
            for (const string& parent : parents[word]) {
                dfs(parent, beginWord, parents, path, result);
            }
        }
        path.pop_back();
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return {}; 

        unordered_map<string, vector<string>> parents; 
        unordered_set<string> visited, currentLevelVisited;
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
                            if (currentLevelVisited.find(temp) == currentLevelVisited.end()) {
                                que.push(temp); 
                                currentLevelVisited.insert(temp);
                            }
                            parents[temp].push_back(word);
                            if (temp == endWord) found = true;
                        }
                    }
                }
            }
            visited.insert(currentLevelVisited.begin(), currentLevelVisited.end()); 
        }

       
        vector<vector<string>> result;
        vector<string> path;
        if (found) {
            dfs(endWord, beginWord, parents, path, result);
        }
        return result;
    }


   
};
