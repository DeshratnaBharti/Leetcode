//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        // Code here
       sort(words.begin(), words.end(), [](const string &a, const string &b) {
        return a.length() < b.length();
    });

    unordered_map<string, int> dp; 
    int maxChain = 1;

    for (const string &word : words) {
        dp[word] = 1; 
        for (int i = 0; i < word.length(); i++) {
            
            string predecessor = word.substr(0, i) + word.substr(i + 1);
            if (dp.find(predecessor) != dp.end()) {
                dp[word] = max(dp[word], dp[predecessor] + 1);
            }
        }
        maxChain = max(maxChain, dp[word]);
    }

    return maxChain; 
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends