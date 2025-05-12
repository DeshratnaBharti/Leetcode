#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& arr) {
        int n = arr.size();
        set<int> ans;  // Unique numbers ke liye set ka istemal
        
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 0) continue;  // Pehla digit 0 nahi ho sakta
            
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) continue;
                    
                    if (arr[k] % 2 == 0) {  // Akhri digit even honi chahiye
                        int num = arr[i] * 100 + arr[j] * 10 + arr[k];
                        ans.insert(num);  // Unique values ko store karo
                    }
                }
            }
        }
        
        return vector<int>(ans.begin(), ans.end());
    }
};
