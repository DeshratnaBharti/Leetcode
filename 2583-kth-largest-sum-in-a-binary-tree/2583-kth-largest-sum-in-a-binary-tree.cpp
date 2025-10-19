class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (root == NULL) return -1;

        vector<long long> s;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            long long sum = 0;

            while (n--) {
                TreeNode* p = q.front(); 
                q.pop();
                sum += p->val;
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }

            s.push_back(sum);
        }

        sort(s.begin(),s.end());
        if (k > s.size()) return -1;
        return s[s.size() - k];
    }
};
