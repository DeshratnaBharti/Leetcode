class Solution {
  public:
        int sum(int n){
        int s =0;
        while(n){
            s = s+n%10;
           n= n/10;
            
        }
        if(s<10) return s;
        return sum(s);
        }
    int digitalRoot(int n) {
        // code here
                int y;
        if(n<10) return n;
        
        else {
            y =sum(n);
        }
        return y;
        
    }
};