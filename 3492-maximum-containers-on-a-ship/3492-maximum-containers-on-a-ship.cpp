class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int count=1,i=0;
        while(w<=maxWeight and i<n*n){
            count++;
            w+=w;
            i++;
        }
        return count;
    }
};