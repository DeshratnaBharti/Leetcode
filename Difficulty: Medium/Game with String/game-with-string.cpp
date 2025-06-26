#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minValue(string &s, int k) {
        unordered_map<char, int> freq;
        
        // Step 1: Count character frequencies
        for (char c : s)
            freq[c]++;

        // Step 2: Use a max heap to store frequencies
        priority_queue<int> pq;
       for (auto it = freq.begin(); it != freq.end(); ++it) {
    pq.push(it->second);
}


        // Step 3: Remove k characters from highest frequency
        while (k-- && !pq.empty()) {
            int top = pq.top();
            pq.pop();
            if (top > 1)
                pq.push(top - 1);
        }
        
        // Step 4: Compute the resulting value
        int result = 0;
        while (!pq.empty()) {
            int val = pq.top();
            pq.pop();
            result += val * val;
        }

        return result;
    }
};
