class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        int m = b.size();
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());

        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> st;
        pq.push({a[0] + b[0], {0, 0}});
        st.insert({0, 0});

        vector<int> ans;
        while (ans.size() < k && !pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int s = t.first;
            int i = t.second.first;
            int j = t.second.second;

            ans.push_back(s);

            if (j + 1 < m && st.find({i, j + 1}) == st.end()) {
                pq.push({a[i] + b[j + 1], {i, j + 1}});
                st.insert({i, j + 1});
            }

            if (i + 1 < n && st.find({i + 1, j}) == st.end()) {
                pq.push({a[i + 1] + b[j], {i + 1, j}});
                st.insert({i + 1, j});
            }
        }

        return ans;
    }
};
