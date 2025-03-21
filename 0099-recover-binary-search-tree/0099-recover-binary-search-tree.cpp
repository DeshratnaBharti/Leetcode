
class Solution {
public:
      TreeNode* first = nullptr;  // Pointer to the first misplaced node
    TreeNode* second = nullptr; // Pointer to the second misplaced node
    TreeNode* prev = nullptr;   // Pointer to the previous node during in-order traversal

    void inorder(TreeNode* root) {
        if (!root) return;

        // Traverse the left subtree
        inorder(root->left);

        // Check for swapped nodes
        if (prev && prev->val > root->val) {
            if (!first) first = prev;
            second = root;
        }
        prev = root;

        // Traverse the right subtree
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
          inorder(root);

        // Swap the values of the two nodes
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};