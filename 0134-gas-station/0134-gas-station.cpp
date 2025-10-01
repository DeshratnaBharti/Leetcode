class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int s= accumulate(gas.begin(), gas.end(), 0);
        int c=accumulate(cost.begin(), cost.end(), 0);
        if(s<c)return -1;
        int total=0,res_ind=0;
        for(int i=0;i<n;i++){
            total = total + gas[i]-cost[i];
            if(total<0) {
                total =0;
                res_ind=i+1;
            }
            
        }
        return res_ind;
        
    }
};