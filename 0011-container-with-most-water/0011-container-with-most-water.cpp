class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0,j = n-1;
        int area ;int maxArea= INT_MIN;
        while(i<=j){
            int l = j-i;
            int h = min(height[i],height[j]);
            area = l*h;
            maxArea = max(area,maxArea);
            if(height[i]>height[j])j--;
            else i++;
        }
        return maxArea;
        
    }
};