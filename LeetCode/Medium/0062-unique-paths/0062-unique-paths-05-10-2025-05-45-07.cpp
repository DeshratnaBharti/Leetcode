class Solution {
public:
    int m,n;
    int f(int i,int j){
        if(i==m-1 and j==n-1) return 1;
        if(i<0 or j<0 or i>=m or j>=n) return 0;
        return f(i+1,j)+f(i,j+1);
    }
    int uniquePaths(int p, int q) {
        m=p;
        n=q;
        return f(0,0);
    }
};