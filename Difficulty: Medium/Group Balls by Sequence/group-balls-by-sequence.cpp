
class Solution {
public:
    bool validgroup(std::vector<int>& arr, int k) {
        int n = arr.size();
        if (n % k != 0) return false;

        std::sort(arr.begin(), arr.end()); // Needed for ordered grouping
        std::unordered_map<int, int> freq;
        for (int num : arr) freq[num]++;

        for (int num : arr) {
            if (freq[num] == 0) continue;
            for (int i = 0; i < k; ++i) {
                if (freq[num + i] == 0) return false;
                freq[num + i]--;
            }
        }
        return true;
    }
};
