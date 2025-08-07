class Solution {
public:
    int n;
    vector<vector<int>>t;
    int child1Coll(vector<vector<int>>&fruits){
        int count =0;
        for(int i=0;i<n;i++){
            count += fruits[i][i];
        }
        return count;
    }
    int child2Coll(int i, int j , vector<vector<int>>&fruits){
        if(i>=n or j<0 or j>=n) return 0;
        if(i==n-1 and j==n-1) return 0;
        if(i==j or i>j) return 0;
        if(t[i][j] != -1) return t[i][j];
        int bL = fruits[i][j]+child2Coll(i+1,j-1,fruits);
        int bD = fruits[i][j]+ child2Coll(i+1,j,fruits);
        int bR = fruits[i][j] + child2Coll(i+1,j+1,fruits);
        return t[i][j]= max({bL,bD,bR});
    }
    int child3Coll(int i, int j , vector<vector<int>>&fruits){
        if(i>=n or j<0 or j>=n) return 0;
        if(i==n-1 and j==n-1) return 0;
        if(i==j or i<j) return 0;
        if(t[i][j] != -1) return t[i][j];
        int uR = fruits[i][j]+child3Coll(i-1,j+1,fruits);
        int R = fruits[i][j]+ child3Coll(i,j+1,fruits);
        int bR = fruits[i][j] + child3Coll(i+1,j+1,fruits);
        return t[i][j]=max({uR,R,bR});
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        t.resize(n,vector<int>(n,-1));
        int c1 = child1Coll(fruits);
        int c2 = child2Coll(0,n-1,fruits);
        int c3 = child3Coll(n-1,0,fruits);
        return c1+c2+c3;
    }
};