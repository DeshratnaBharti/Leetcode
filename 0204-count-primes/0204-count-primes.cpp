class Solution {
public:
    int countPrimes(int n) {
        if(n==2) return 0;
        if(n==0 or n==1) return 0;
        vector<bool> isPrime(n+1, true); 
        int primeCount = 0; 
      
    
        for (int i = 2; i*i <=n; i++) { 
            if (isPrime[i]) { 
                
                for (long long j = (long long)i * i; j < n; j += i) {
                    isPrime[j] = false; 
                }
            }
        }
        for(int i=2;i<isPrime.size();i++){
            if(isPrime[i]) primeCount++;
        }
        return primeCount-1;
        
    }
};