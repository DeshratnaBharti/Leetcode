class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val < root->val && q->val < root->val) {
                root = root->left; // Move to the left subtree
            } else if (p->val > root->val && q->val > root->val) {
                root = root->right; // Move to the right subtree
            } else {
                return root; // Found the LCA
            }
        }
        return nullptr;
    }
};