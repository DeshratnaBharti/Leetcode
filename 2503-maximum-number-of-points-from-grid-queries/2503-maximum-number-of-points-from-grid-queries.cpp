class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int k = queries.size();
        
        vector<int> res(k); // Result array
        vector<pair<int, int>> sortedQueries; // To store queries with their indices
        
        for (int i = 0; i < k; ++i) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end()); // Sort queries by value
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq; 
        pq.push({grid[0][0], {0, 0}}); // Push starting cell with its value
        visited[0][0] = true;

        int points = 0; // Count of visited cells
        
        for (auto& query : sortedQueries) {
            int qValue = query.first;
            int qIndex = query.second;

            // Process all cells with values < current query value
            while (!pq.empty() && pq.top().first < qValue) {
                auto [value, cell] = pq.top(); pq.pop();
                int x = cell.first, y = cell.second;

                points++; // Count this cell as visited
                
                // Check neighbors
                vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
                for (auto dir : directions) {
                    int nx = x + dir.first, ny = y + dir.second;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        pq.push({grid[nx][ny], {nx, ny}});
                    }
                }
            }

            // Store the result for the current query
            res[qIndex] = points;
        }

        return res; // Return the results
    }
};
