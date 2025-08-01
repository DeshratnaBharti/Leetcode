class Solution {
public:
    int n;

    pair<int,int> getCoord(int num) {
        int RT = (num - 1) / n;
        int RB = (n - 1) - RT;
        int col = (num - 1) % n;

        if ((RT % 2) == 1) { // Alternate rows have reversed numbering
            col = (n - 1) - col;
        }
        return {RB, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        int steps = 0;
        queue<int> que;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        visited[n - 1][0] = true;
        que.push(1);

        while (!que.empty()) {
            int N = que.size();
            while (N--) {
                int x = que.front();
                que.pop(); // Popping the current element

                if (x == n * n) return steps;

                for (int k = 1; k <= 6; k++) {
                    int val = x + k;
                    if (val > n * n) break;

                    pair<int, int> coord = getCoord(val);
                    int r = coord.first;
                    int c = coord.second;

                    if (visited[r][c]) continue;

                    visited[r][c] = true;

                    if (board[r][c] == -1) {
                        que.push(val);
                    } else {
                        que.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
