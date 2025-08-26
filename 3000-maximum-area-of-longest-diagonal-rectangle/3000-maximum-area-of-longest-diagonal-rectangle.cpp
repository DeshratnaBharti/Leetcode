class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& arr) {
        double maxD =0;
        int maxA=0;
        for(auto &a:arr){
            int p = a[0];
            int q = a[1];
             double diag = sqrt(p * p + q * q);
            int A = p*q;
            
            if(maxD<diag){
                maxD = diag;
                maxA =A;
            }
            else if(diag == maxD){
                maxA =max(maxA,A);
            }
        }
        return maxA;
    }
};