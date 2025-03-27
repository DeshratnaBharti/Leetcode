class Solution {
public:
    int minimumIndex(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        for(int &num:arr) mp2[num]++;

        for(int i=0;i<n;i++){
            int num = arr[i];
            mp1[num]++;
            mp2[num]--;
            int n1 = i+1;
            int n2 = n-i-1;
            if(mp1[num] >n1/2 and mp2[num]>n2/2) return i;
            

        }
        return -1;
    }
};