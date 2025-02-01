/***
Job Sequencing Problem
Difficulty: MediumAccuracy: 34.51%Submissions: 275K+Points: 4
You are given three arrays: id, deadline, and profit, where each job is associated with an ID, a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

Your task is to find:

The maximum number of jobs that can be completed within their deadlines.
The total maximum profit earned by completing those jobs.
Examples :

Input: id = [1, 2, 3, 4], deadline = [4, 1, 1, 1], profit = [20, 1, 40, 30]
Output: [2, 60]
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).
Input: id = [1, 2, 3, 4, 5], deadline = [2, 1, 2, 1, 1], profit = [100, 19, 27, 25, 15]
Output: [2, 127]
Explanation: Job1 and Job3 can be done with maximum profit of 127 (100+27).
Input: id = [1, 2, 3, 4], deadline = [3, 1, 2, 2], profit = [50, 10, 20, 30]
Output: [3, 100]
Explanation: Job1, Job3 and Job4 can be completed with a maximum profit of 100 (50 + 20 + 30).
Constraints:
1 <=  id.size() == deadline.size() == profit.size() <= 105
1 <= id[i], deadline[i] <= id.size()
1 <= profit <= 500

***/


class Solution {
public:
    vector<int> JobSequencing(vector<int>& id, vector<int>& deadline, vector<int>& profit) {
        int n = id.size();
        vector<vector<int>> arr(n, vector<int>(3, 0));

        for (int i = 0; i < n; i++) {
            arr[i][0] = profit[i];
            arr[i][1] = deadline[i];
            arr[i][2] = id[i];
        }

        // Sort jobs in decreasing order of profit
        sort(arr.begin(), arr.end(), [&](auto& vec1, auto& vec2) {
            return vec1[0] > vec2[0];
        });

        int maxmDead = 0;
        for (int i = 0; i < n; i++) {
            maxmDead = max(maxmDead, arr[i][1]);
        }

        vector<int> slot(maxmDead + 1, -1);

        int countJobs = 0, jobProfit = 0;

        for (int i = 0; i < n; i++) {
            for (int j = arr[i][1]; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = 1;
                    countJobs++;
                    jobProfit += arr[i][0];
                    break;
                }
            }
        }

        return {countJobs, jobProfit};
    }
