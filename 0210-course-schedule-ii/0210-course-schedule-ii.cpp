class Solution {
public:
    vector<int> topSort(vector<vector<int>>& adj, vector<int>& indegree, int n) {
        queue<int> que;
        vector<int> result;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                result.push_back(i);
                que.push(i);
                count++;
            }
        }

        while (!que.empty()) {
            int a = que.front();
            que.pop();

            for (int& b : adj[a]) {
                indegree[b]--;
                if (indegree[b] == 0) {
                    result.push_back(b);
                    que.push(b);
                    count++;
                }
            }
        }

        if (count == n) return result;
        return {};
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        return topSort(adj, indegree, numCourses);
    }
};
