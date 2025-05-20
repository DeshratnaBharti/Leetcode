class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());

        int m = g.size();
        int n = s.size();
        int i=0,j=0;
        while(i<m and j<n){
            if(g[i] <= s[j]){
                i++;
            }
            j++;
        }
        return i;
    }
};