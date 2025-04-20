class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mp;
        for(auto &x:answers){
            mp[x]++;
        }
        int total=0;
        for(auto &it:mp){
            int x=it.first;
            int count =it.second;
            int groupSige=x+1;
            int groups=ceil((double)count/groupSige);
            total += groups*groupSige;
        }
        return total;
    }
};