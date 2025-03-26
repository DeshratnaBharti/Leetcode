class Solution {
public:
    int totalNumbers(vector<int>& arr) {
        unordered_set<int>st;
        int n= arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]==0) continue;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                for(int k=0;k<n;k++){
                    if(i==k or j==k)  continue;
                    if(arr[k]%2==0){
                        int num = arr[i]*100+arr[j]*10+arr[k];
                        st.insert(num);
                    }
                }
            }
        }
        return st.size();
    }
};