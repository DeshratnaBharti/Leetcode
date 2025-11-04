class BSTIterator {
private:
    vector<int> inorder;
    int i = 0;

    void inorderTraversal(TreeNode* root) {
        if (!root) return;
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
    }

public:
    BSTIterator(TreeNode* root) {
        inorderTraversal(root);
    }

    int next() {
        return inorder[i++];
    }

    bool hasNext() {
        return i < inorder.size();
    }
};
