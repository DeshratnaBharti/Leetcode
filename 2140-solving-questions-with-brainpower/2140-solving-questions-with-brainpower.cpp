class Solution {
public:
    long long solve(vector<vector<int>>& questions, int i, int n, vector<long long>& t) {
        // Base Case: If the index goes out of bounds
        if (i >= n) return 0;

        // Check memoized value
        if (t[i] != -1) return t[i];

        // Option 1: Solve the current question
        long long solveCurrent = questions[i][0];
        if (i + questions[i][1] + 1 < n) {
            solveCurrent += solve(questions, i + questions[i][1] + 1, n, t);
        }

        // Option 2: Skip the current question
        long long skipCurrent = solve(questions, i + 1, n, t);

        // Memoize and return the maximum of the two options
        return t[i] = max(solveCurrent, skipCurrent);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> t(n, -1); // Dynamic memoization array
        return solve(questions, 0, n, t);
    }
};
