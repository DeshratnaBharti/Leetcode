class Solution {
public:
    int firstUniqChar(string s) {
    unordered_map<char, int> count;
    queue<pair<char, int>> q;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        count[ch]++;
        q.push({ch, i});

      
        while (!q.empty() && count[q.front().first] > 1) {
            q.pop();
        }
    }

    return q.empty() ? -1 : q.front().second;
    }
};