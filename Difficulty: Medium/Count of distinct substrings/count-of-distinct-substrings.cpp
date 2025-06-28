#include <iostream>
#include <unordered_map>
using namespace std;

// Trie Node definition
struct TrieNode {
    unordered_map<char, TrieNode*> children;
};

int countDistinctSubstring(string str) {
    TrieNode* root = new TrieNode();
    int count = 0;

    // Insert all suffixes into the Trie
    for (int i = 0; i < str.length(); ++i) {
        TrieNode* node = root;
        for (int j = i; j < str.length(); ++j) {
            char ch = str[j];
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
                count++;  // New node = new unique substring
            }
            node = node->children[ch];
        }
    }

    return count + 1; // +1 for the empty substring
}
