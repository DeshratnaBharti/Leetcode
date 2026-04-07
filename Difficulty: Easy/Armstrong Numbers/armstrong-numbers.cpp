// User function Template for C++
class Solution {
  public:
    
    bool armstrongNumber(int n) {
        // code here
        int z = n;
        int s =0;
        while(n){
            int y = n%10;
            s = s + pow(y,3);
            n = n/10;
            
        }
        if(s==z) return true;
        return false;
    }
};