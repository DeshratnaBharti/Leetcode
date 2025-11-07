class Solution {
public:
    TreeNode* iop(TreeNode* root){
        TreeNode* pred = root->left;
        while(pred->right){
            pred=pred->right;
        }
        return pred;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
      if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            
            if (!root->left) return root->right; 
            if (!root->right) return root->left; 
            
            TreeNode* pred = iop(root);
            root->val = pred->val;
            root->left = deleteNode(root->left, pred->val);
        }
        return root;
    }
};