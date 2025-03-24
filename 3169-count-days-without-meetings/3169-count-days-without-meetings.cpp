#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // Sort meetings by their ending day
        sort(meetings.begin(), meetings.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int res = 0; // Count of days without meetings
        int lastMeetingEnd = 0; // Tracks the last meeting end day

        for (auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];

            // Count days between the last meeting's end and the start of the current meeting
            if (start > lastMeetingEnd + 1) {
                res += start - lastMeetingEnd - 1;
            }

            // Update the last meeting end day
            lastMeetingEnd = max(lastMeetingEnd, end);
        }

        // Count remaining days after the last meeting ends
        if (days > lastMeetingEnd) {
            res += days - lastMeetingEnd;
        }

        return res;
    }
};
