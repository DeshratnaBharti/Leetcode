class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> minPQ;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                minPQ.push(matrix[i][j]);
            }
        }
        int x;
        while(k--){
            x = minPQ.top();
            minPQ.pop();
        }
        return x;

    }
};