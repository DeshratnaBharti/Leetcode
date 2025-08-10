class Solution {
  public:
    int countPS(string &s) {
        // code here
         int n = s.size();
    int count = 0;

    for (int center = 0; center < 2 * n - 1; ++center) {
        int left = center / 2;
        int right = left + (center % 2);

        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 >= 2) {
                count++;
            }
            left--;
            right++;
        }
    }

    return count;
}
    
};