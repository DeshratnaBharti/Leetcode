class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0) return false;
        else if(n%3==0) return true;
        else return false;
    }
};