class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN and divisor==-1) return INT_MAX;
        if(dividend==INT_MIN and divisor==1) return INT_MIN;
        
        long int dd = abs(dividend);
        long int dv = abs(divisor);
        
        int ans =0;
        while(dv <= dd){
            long int sum = dv,count =1;
            while(sum <= dd-sum){
                sum +=sum;
                count += count;
            }
            ans += count;
            dd -= sum;
        }
        if((dividend <0 and divisor>0 )or (dividend >0 and divisor<0) )return -ans;
        
        return ans;
    }
};