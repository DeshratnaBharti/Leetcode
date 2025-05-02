class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> rightClosestL(n, -1);
        vector<int> leftClosestR(n, -1);
        
        // Fill leftClosestR
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') leftClosestR[i] = i;
            else if (dominoes[i] == '.' && i > 0) leftClosestR[i] = leftClosestR[i - 1];
        }
        
        // Fill rightClosestL
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') rightClosestL[i] = i;
            else if (dominoes[i] == '.' && i < n - 1) rightClosestL[i] = rightClosestL[i + 1];
        }
        
        string result(n, '.'); // Initialize with dots
        for (int i = 0; i < n; i++) {
            if (rightClosestL[i] == leftClosestR[i]) continue; // If same index, it remains '.'
            
            int distRightL = (rightClosestL[i] == -1) ? INT_MAX : abs(i - rightClosestL[i]);
            int distLeftR = (leftClosestR[i] == -1) ? INT_MAX : abs(i - leftClosestR[i]);
            
            if (distRightL < distLeftR) result[i] = 'L';
            else if (distLeftR < distRightL) result[i] = 'R';
        }
        
        return result;
    }
};
