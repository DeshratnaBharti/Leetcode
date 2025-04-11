//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   string findOrder(vector<string> &words) {
    // Step 1: Initialize adjacency list and indegree map
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> indegree;

    // Step 2: Populate adjacency list with all unique characters
    for (const string &word : words) {
        for (char c : word) {
            adj[c]; // Ensure each character is present in the adjacency list
            indegree[c] = 0; // Initialize indegree to 0 for each character
        }
    }

    // Step 3: Build the graph by comparing adjacent words
    for (int i = 0; i < words.size() - 1; ++i) {
        string word1 = words[i], word2 = words[i + 1];
        int minLength = min(word1.length(), word2.length());
        bool foundDifference = false;

        for (int j = 0; j < minLength; ++j) {
            if (word1[j] != word2[j]) {
                if (!adj[word1[j]].count(word2[j])) { // Avoid duplicate edges
                    adj[word1[j]].insert(word2[j]);
                    indegree[word2[j]]++;
                }
                foundDifference = true;
                break;
            }
        }

        // If word2 is a prefix of word1 but comes later, the order is invalid
        if (!foundDifference && word1.length() > word2.length()) {
            return "";
        }
    }

    // Step 4: Perform topological sort using Kahn's Algorithm
    queue<char> q;
    for (const auto &pair : indegree) {
        if (pair.second == 0) q.push(pair.first);
    }

    string order;
    while (!q.empty()) {
        char c = q.front();
        q.pop();
        order += c;

        for (char neighbor : adj[c]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) q.push(neighbor);
        }
    }

    // Step 5: Check for cycles
    if (order.length() != indegree.size()) return "";

    return order;


    }
};


//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends