class Solution {
public:
    int maxBottlesDrunk(int nB, int nE) {
        int ans = nB;
        int E = nB;
        int f=0;
        while(E+f>=nE){
            E= E-nE;
            f++;
            ans++;
            nE++;
        }
        return ans;
    }
};