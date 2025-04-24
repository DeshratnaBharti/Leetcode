class Solution {
public:
    int countCompleteSubarrays(vector<int>&arr) {
        int n=arr.size();
        set<int> uniqueElements;
        for (int num : arr) {
             uniqueElements.insert(num);
        }
        int sizeofUnEle = uniqueElements.size();
        int count=0;
        for(int i=0;i<n;i++){
            unordered_set<int>st;
            for(int j=i;j<n;j++){
                st.insert(arr[j]);
                if(st.size()==sizeofUnEle) count++;
            }
        }
        return count;
    }
};