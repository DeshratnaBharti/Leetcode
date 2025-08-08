class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int k=0;k<=31;k++){
            int temp = (1<<k);
            int cg=0;
            int co =0;
            for(int &num:nums){
                if((num & temp) ==0){
                    cg++;
                }
                else{
                    co++;
                }
            }
            if(co%3==1){
                result |=temp;
            }
        }
       
        return result;
    }
};