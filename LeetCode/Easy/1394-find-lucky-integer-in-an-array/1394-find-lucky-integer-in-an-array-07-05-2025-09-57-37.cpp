class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int num : arr) {
            mp[num]++;
        }

        int lucky = -1;
        for (auto [num, freq] : mp) {
            if (num == freq && num > lucky) {
                lucky = num;
            }
        }

        return lucky;
    }
};
