class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0];
        int b=nums[1];
        int c = nums[2];
        if(a==b and b==c) return "equilateral";
        if(a != b and b!= c and a!=c) return "scalene";
        if((a==b and a!=c) or (b==c and c!=a) or (c==a and c!=b))return "isosceles";
        return "none";
    }
};