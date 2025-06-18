class Solution {
public:
    int t[105][105];

    int f(int i, int j, vector<int>& cuts) {
        if (i + 1 == j) return 0; // no space to cut between
        if (t[i][j] != -1) return t[i][j];
        int ans = INT_MAX;

        for (int k = i + 1; k < j; ++k) {
            int cost = f(i, k, cuts) + f(k, j, cuts) + cuts[j] - cuts[i];
            ans = min(ans, cost);
        }
        return t[i][j] = ans;
    }

    int minCost(int n, vector<int>& cut) {
        cut.push_back(0);
        cut.push_back(n);
        sort(cut.begin(), cut.end());
        memset(t, -1, sizeof(t));
        return f(0, cut.size() - 1, cut);
    }
};
