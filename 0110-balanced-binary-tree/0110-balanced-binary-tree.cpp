
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        std::function<int(TreeNode*)> findHeight = [&](TreeNode* node) -> int {
            if (!node) {
                // Tree is empty or this is a leaf node, hence the height is 0.
                return 0;
            }
            int leftHeight = findHeight(node->left);
            int rightHeight = findHeight(node->right);

            if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
                // If the left or right subtree is unbalanced, or if the current subtree
                // is unbalanced (difference in height > 1), return -1 as an indicator.
                return -1;
            }
            // Otherwise, calculate the height of this subtree,
            // which is 1 + the maximum height of its left or right subtree.
            return 1 + std::max(leftHeight, rightHeight);
        };
      
        // If the height function returns -1, the tree is unbalanced.
        // Otherwise, it is balanced.
        return findHeight(root) >= 0;
    }
};