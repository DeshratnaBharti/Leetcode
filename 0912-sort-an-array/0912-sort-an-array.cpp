class Solution {
public:
    void merge(vector<int>& nums, int st, int mid, int end) {
        vector<int> temp;
        int i = st, j = mid + 1;
        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }
        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= end) temp.push_back(nums[j++]);

        for (int idx = 0; idx < temp.size(); idx++) {
            nums[st + idx] = temp[idx];
        }
    }

    void m(vector<int>& nums, int s, int e) {
        if (s >= e) return;
        int mid = (s + e) / 2;
        m(nums, s, mid);
        m(nums, mid + 1, e);
        merge(nums, s, mid, e);
    }

    vector<int> sortArray(vector<int>& nums) {
        m(nums, 0, nums.size() - 1);
        return nums;
    }
};
