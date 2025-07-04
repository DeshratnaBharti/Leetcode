class Solution {
public:
    char kthCharacter(long long k, vector<int>& arr) {
        if(k==1) return 'a';
        int n = arr.size();
        long long len =1;
        long long newK =-1,op=-1;
        for(int i=0;i<n;i++){
            len *=2;
            if(len>=k){
                op = arr[i];
                newK = k-len/2;
                break;
            }
        }
        char ch = kthCharacter(newK,arr);
        if(op==0) return ch;
        return ch+1;
    }
};