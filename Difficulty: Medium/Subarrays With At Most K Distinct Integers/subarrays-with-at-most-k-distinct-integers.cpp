class Solution {
public:
    int countAtMostK(vector<int> &arr, int k) {
        unordered_map<int, int> mp;
        int n = arr.size();
        int i = 0, j = 0;
        int count = 0;

        for (j = 0; j < n; ++j) {
            mp[arr[j]]++;

            while (mp.size() > k) {
                mp[arr[i]]--;
                if (mp[arr[i]] == 0) {
                    mp.erase(arr[i]);
                }
                i++;
            }

            count += (j - i + 1);  // All subarrays ending at j with at most k distinct
        }

        return count;
    }

    int subarraysWithAtMostKDistinct(vector<int>& arr, int k) {
        return countAtMostK(arr, k);
    }
};
