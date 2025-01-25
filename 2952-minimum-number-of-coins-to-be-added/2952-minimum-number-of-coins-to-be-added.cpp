class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int obtainable =0;
        int added =0;
        sort(coins.begin(),coins.end());
        for(auto coin:coins){
            while(coin>obtainable+1){
                added++;
                int newCoin = obtainable+1;
                obtainable += newCoin;
                if(obtainable >= target) return added;

            }
            obtainable += coin;
            if(obtainable >= target) return added;
        }
        while(obtainable<target){
            added++;
            int newCoin = obtainable+1;
            obtainable += newCoin;
        }
        return added;
    }
};