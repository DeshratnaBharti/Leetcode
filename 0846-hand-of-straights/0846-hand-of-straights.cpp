class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int m) {
        int n = hand.size();
        if(n % m != 0 ) return false;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }

        while(!mp.empty()){
            int x = mp.begin()->first;
          
            for(int i=0;i<m;i++){
                
                if(mp[x+i] ==0) return false;
               
            
                mp[x+i]--;
                if(mp[x+i]<1) mp.erase(x+i);
            }
        }
        return true;
    }
};