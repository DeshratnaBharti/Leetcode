#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

class Trie {
public:
    Trie() : children(2, nullptr) {}

    void insert(int number) {
        Trie* node = this;
        for (int bitIndex = 30; bitIndex >= 0; --bitIndex) {
            int bitValue = (number >> bitIndex) & 1;
            if (!node->children[bitValue]) {
                node->children[bitValue] = new Trie();
            }
            node = node->children[bitValue];
        }
    }

    int search(int number) {
        int maxXor = 0;
        Trie* node = this;
        for (int bitIndex = 30; bitIndex >= 0; --bitIndex) {
            int bitValue = (number >> bitIndex) & 1;
            if (node->children[bitValue ^ 1]) {
                node = node->children[bitValue ^ 1];
                maxXor |= 1 << bitIndex;
            } else if (node->children[bitValue]) {
                node = node->children[bitValue];
            } else {
                return -1;
            }
        }
        return maxXor;
    }

private:
    vector<Trie*> children;
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        int numQueries = queries.size();
        vector<tuple<int, int, int>> extendedQueries;
        for (int i = 0; i < numQueries; ++i) {
            extendedQueries.emplace_back(queries[i][1], queries[i][0], i);
        }
        sort(extendedQueries.begin(), extendedQueries.end());
        Trie* trie = new Trie();
        int numsIndex = 0;
        vector<int> answers(numQueries);
        for (const auto& [maxWith, xorWith, originalIndex] : extendedQueries) {
            while (numsIndex < nums.size() && nums[numsIndex] <= maxWith) {
                trie->insert(nums[numsIndex++]);
            }
            answers[originalIndex] = trie->search(xorWith);
        }
        return answers;
    }
};
