class Solution {
public:
    class FenwickTree {
    private:
        vector<int> tree;
        int size;
    public:
        FenwickTree(int n) : size(n), tree(n + 1, 0) {}

        void update(int index, int value) {
            while (index <= size) {
                tree[index] += value;
                index += index & -index;
            }
        }

        int query(int index) {
            int sum = 0;
            while (index > 0) {
                sum += tree[index];
                index -= index & -index;
            }
            return sum;
        }
    };

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        // Map indices from nums2 to their positions in nums1
        unordered_map<int, int> position;
        for (int i = 0; i < n; ++i) {
            position[nums1[i]] = i;
        }
        vector<int> mappedIndices(n);
        for (int i = 0; i < n; ++i) {
            mappedIndices[i] = position[nums2[i]];
        }

        FenwickTree leftTree(n), rightTree(n);

        // Initialize the right tree
        for (int index : mappedIndices) {
            rightTree.update(index + 1, 1);
        }

        long long result = 0;
        for (int j = 0; j < n; ++j) {
            int midIndex = mappedIndices[j];
            rightTree.update(midIndex + 1, -1);

            long long leftCount = leftTree.query(midIndex);
            long long rightCount = rightTree.query(n) - rightTree.query(midIndex);

            result += leftCount * rightCount;

            leftTree.update(midIndex + 1, 1);
        }

        return result;
    }
};
