
class Solution {
public:
    TreeNode* lastVisited = nullptr;
    void flatten(TreeNode* root) {
        if (root==nullptr) return;
        flatten(root->right);
        flatten(root->left);
        root->left=NULL;
        root->right=lastVisited;
        lastVisited = root;
    }
};