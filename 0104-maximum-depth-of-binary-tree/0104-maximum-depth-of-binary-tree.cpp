
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) 
            return 0;

        // Recursively compute the depth of the left subtree
        int leftDepth = maxDepth(root->left);
        // Recursively compute the depth of the right subtree
        int rightDepth = maxDepth(root->right);

        // The maximum depth of the current node is 1 (for the current node) plus
        // the greater depth between the left and right subtrees
        return 1 + max(leftDepth, rightDepth);
    }
};