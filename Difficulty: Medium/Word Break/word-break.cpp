//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }

    bool search(const string& s, int start, TrieNode* node, vector<int>& dp) {
        TrieNode* curr = node;
        for (int i = start; i < s.length(); i++) {
            if (!curr->children.count(s[i])) return false;
            curr = curr->children[s[i]];
            if (curr->isEndOfWord && dp[i + 1]) return true;
        }
        return false;
    }
};
    bool wordBreak(string &s, vector<string> &dictionary) {
          int n = s.length();
    Trie trie;

    for (const string& word : dictionary) {
        trie.insert(word); // Insert all words into the Trie
    }

    vector<int> dp(n + 1, 0);
    dp[n] = 1; // Base case: empty suffix is valid

    for (int i = n - 1; i >= 0; i--) {
        if (trie.search(s, i, trie.root, dp)) {
            dp[i] = 1;
        }
    }

    return dp[0];
        
    }
};


//{ Driver Code Starts.

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) {
            cout << "true\n";
        } else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends