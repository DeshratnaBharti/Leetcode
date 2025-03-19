class Solution {
public:
    int minOperations(vector<int>& arr) {
        int n = arr.size();
        int flips =0;
        int k=3;
        int flipCountFromPasti=0;
        vector<bool>isFlipped(n,false);
        for(int i=0;i<n;i++){
            if(i>=k and isFlipped[i-k]){
                flipCountFromPasti--;
            }
            if(flipCountFromPasti %2 == arr[i]){
                if(i+k >n) return -1;
                flipCountFromPasti++;
                flips++;
                isFlipped[i]= true;
            }
        }
        return flips;
    }
};