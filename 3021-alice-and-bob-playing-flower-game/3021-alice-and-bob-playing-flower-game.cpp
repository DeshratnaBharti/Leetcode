class Solution {
public:
    long long flowerGame(int n, int m) {
        int a = ceil(n/2.0);
        int b = floor(n/2);
        int c = ceil(m/2.0);
        int d = floor(m/2);
        return 1LL * a * d + 1LL * b * c;
    }
};