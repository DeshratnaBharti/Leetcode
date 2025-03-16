
class Solution {
public:
    vector<int> result;
     void inorder(TreeNode* root) {
        if (root == nullptr) return;

        inorder(root->left);   // Step 1: Left subtree
        result.push_back(root->val);  // Step 2: Root node
        inorder(root->right); // Step 3: Right subtree
    }
    int kthSmallest(TreeNode* root, int k) {
       // vector<int> result;
        inorder(root);
        return result[k-1];
    }
};