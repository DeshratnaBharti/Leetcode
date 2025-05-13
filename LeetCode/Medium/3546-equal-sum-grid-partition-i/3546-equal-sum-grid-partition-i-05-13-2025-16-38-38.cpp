class Solution {
public:
    
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long totalSum = 0;  
        for (const auto& row : grid) {
            for (int num : row) {
                totalSum += num;
            }
        }

        
        if (totalSum % 2 != 0) return false;
        
        long long halfSum = totalSum / 2;
        long long rowSum = 0;

        vector<int>rowS(m,0),colS(n,0);
        for (int i = 0; i < m ; i++) {  
            for (int j = 0; j < n; j++) {
                rowSum += grid[i][j];
            }
            rowS[i]=rowSum;
        }
        
        long long colSum = 0;

        
        for (int j = 0; j < n ; j++) {  
            for (int i = 0; i < m; i++) {
                colSum += grid[i][j];
            }
            colS[j]=colSum;
        }
        int s1=0;
        for(int i=0;i<m;i++){
             s1 += rowS[i];
            if(s1==halfSum) return true;
        }
        int s2=0;
        for(int i=0;i<n;i++){
            s2 += colS[i];
            if(s2==halfSum) return true;
        }
        
        return false;
    }
};