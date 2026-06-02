class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        int i =0,j=0;
        while(j<n){
            while(j<n and arr[i]==arr[j]) j++;
            if(j < n) {
             arr[i+1] = arr[j];
             i++;
            }
        }
        return i+1;
        
    }
};