class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        bool flag = false;
        for(int i=2;i<arr.size()-1;i++){
            if( arr[i-2]%2 != 0 and arr[i-1]%2 !=0 and arr[i]%2 != 0){
                flag = true;
                break;
            }
        }
        if(flag ==false) return false;
        return true;
    }
};