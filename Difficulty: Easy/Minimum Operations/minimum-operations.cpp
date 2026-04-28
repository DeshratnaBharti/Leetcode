class Solution {
  public:
    int minOperation(int n) {
        int count = 0;
        while (n > 1) {
            if (n % 2 == 0)
                n /= 2;
            else
                n -= 1;
            count++;
        }
        return 1+count;

    }
};