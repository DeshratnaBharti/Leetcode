class Solution {
public:
    int numberOfArrays(vector<int>& diff, int l, int u) {
        int curr=0;
        int minV=0;
        int maxV=0;
        for(int &d:diff){
            curr=curr+d;
            minV=min(minV,curr);
            maxV=max(maxV,curr);
            if((u- maxV)-(l-minV)+1 <=0) return 0;
        }
        return (u- maxV)-(l-minV)+1;
    }
};