class Solution {
public:
    int M = 1e9+7;
    int t[301][301];
    int solve(int n,int num,int x){
        if(n==0) return 1;
        if(n<0) return 0;
        int currPv = pow(num,x);
        if(currPv > n)return 0;
        int take = solve(n-currPv,num+1,x);
        int not_take = solve(n , num+1,x);
        return t[n][num]=(take+not_take)%M;

    }
    int numberOfWays(int n, int x) {
        memset(t,-1,sizeof(t));
       return solve(n,1,x);
    }
};