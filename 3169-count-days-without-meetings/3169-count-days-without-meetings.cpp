#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& arr) {
        // Sort the meetings based on their start and end days
        sort(arr.begin(), arr.end());
        
        int res = 0; // Count of days without meetings
        int e = 0;   // Tracks the last meeting end day
        
        for (int i = 0; i < arr.size(); i++) {
            // Count days between the previous end day and the start of the current meeting
            if (arr[i][0] > e + 1) {
                res += arr[i][0] - e - 1;
            }
            // Update the last meeting end day
            e = max(e, arr[i][1]);
        }
        
        // Count remaining days after the last meeting ends
        if (days > e) {
            res += days - e;
        }
        
        return res;
    }
};
