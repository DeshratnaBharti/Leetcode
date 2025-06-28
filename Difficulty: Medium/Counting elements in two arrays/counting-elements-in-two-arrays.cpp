class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        int m = a.size();
        vector<int> ans(m, 0);
        sort(b.begin(), b.end());

        for (int i = 0; i < m; i++) {
            // upper_bound returns iterator to first element > a[i]
            ans[i] = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        }

        return ans;
    }
};
