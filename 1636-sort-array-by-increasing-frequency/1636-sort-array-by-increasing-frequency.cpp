class Solution {
public:
    
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto a:nums){
            mp[a]++;
        }
        vector<pair<int,int>>v;
        for(auto a:mp){
            int b = a.first;
            int c = a.second;
            v.push_back({b,c});
        }
        sort(v.begin(),v.end(),[](pair<int,int>a,pair<int,int>b){
            if(a.second ==b.second){
                if(a.first >b.first) return true;
                else return false;
            }else{
                if(a.second>b.second)return false;
                else return true;
            }
        });
        vector<int>ans;
        for(auto &p : v){
            for(int i=0; i<p.second; i++){
                ans.push_back(p.first);
            }
        }
        return ans;
        
        
        
        
    }
};