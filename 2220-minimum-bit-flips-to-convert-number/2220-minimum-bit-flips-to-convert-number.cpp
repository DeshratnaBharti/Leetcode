class Solution {
public:
    int minBitFlips(int start, int goal) {
      int n= start xor goal;
    long long count =0;
        while(n){
            if((n& 1) == 1)count++;
           n= n>>1;
        }
        return (int)count;
    }
};