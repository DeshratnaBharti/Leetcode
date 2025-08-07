class Solution {
  public:
    int minDifference(vector<string> &arr) {
        int n = arr.size();
        vector<int> seconds(n);
        for(int i = 0; i < n; i++) {
            int h = stoi(arr[i].substr(0, 2));
            int m = stoi(arr[i].substr(3, 2));
            int s = stoi(arr[i].substr(6, 2));
            seconds[i] = h * 3600 + m * 60 + s;
        }

        sort(seconds.begin(), seconds.end());
        int diff = INT_MAX;
        for(int i = 1; i < n; i++) {
            diff = min(diff, seconds[i] - seconds[i - 1]);
        }

        int rotation = 24 * 60 * 60;
        diff = min(diff, seconds[0] + rotation - seconds[n - 1]);
        return diff;
    }
};
