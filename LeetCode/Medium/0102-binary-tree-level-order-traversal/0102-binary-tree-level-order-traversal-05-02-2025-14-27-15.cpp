class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {}; // Handle empty tree

        vector<vector<int>> result;
        queue<TreeNode*> que;
        que.push(root);
        
        while (!que.empty()) {
            int n = que.size();
            vector<int> ans;
            for (int i = 0; i < n; i++) {
                TreeNode* front = que.front();
                que.pop();
                ans.push_back(front->val);
                if (front->left) que.push(front->left);
                if (front->right) que.push(front->right);
            }
            result.push_back(ans); // Only add non-empty levels
        }
        
        return result;
    }
};
