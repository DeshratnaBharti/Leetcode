class Solution {
public:
    long long power(int a,int b,int MOD){
        if(b==0) return 1;
        long long result;
        long long half=power(a,b/2,MOD);
        
        result = (half*half )%MOD;

        if(b %2 ==1){
            result = (result*a)%MOD;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        const int MOD = 1e9 + 7;
    long long evenCount = (n + 1) / 2; // Number of even positions
    long long oddCount = n / 2;       // Number of odd positions
    
    // Calculate powers modulo
    long long evenChoices = power(5, evenCount, MOD);
    long long oddChoices = power(4, oddCount, MOD);
    
    // Final result
    return (evenChoices * oddChoices) % MOD;
    }
};