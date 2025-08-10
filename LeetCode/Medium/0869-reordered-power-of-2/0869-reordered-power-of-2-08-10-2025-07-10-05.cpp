class Solution {
public:
    bool cA(vector<int>&iDf,vector<int>&pow2fc){
        for(int i=0;i<10;i++){
            if(iDf[i] != pow2fc[i]) return false;
        }
        return true;
    }
    vector<int>fC(int n){
        vector<int>dif(10,0);
        while(n>0){
            dif[n%10]++;
            n/=10;
        }
        return dif;
    }
    bool reorderedPowerOf2(int n) {
        vector<int>iDf = fC(n);
        for(int i=0;i<31;i++){
            int pow2 = 1<<i;
            vector<int>pow2fc = fC(pow2);
            if(cA(iDf,pow2fc)) return true;

        }
        return false;
    }
};