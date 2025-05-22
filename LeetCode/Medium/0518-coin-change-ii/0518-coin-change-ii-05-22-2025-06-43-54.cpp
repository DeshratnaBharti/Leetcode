class Solution {
public:
 int n;
    int f(int amount, vector<int>& coins,int i,int s){
        if (i == n || s > amount) return 0;
        if(s==amount)return 1;
        int take = f(amount,coins,i,s+coins[i]);
        int not_take=f(amount,coins,i+1,s);
        return take +not_take;
    }
    int change(int amount, vector<int>& coins) {
         n=coins.size();
        return f(amount,coins,0,0);
    }
};