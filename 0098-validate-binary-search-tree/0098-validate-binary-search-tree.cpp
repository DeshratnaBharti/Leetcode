
class Solution {
public: 
     vector<int> result;
     void inorder(TreeNode* root) {
        if (root == nullptr) return;

        inorder(root->left);   // Step 1: Left subtree
        result.push_back(root->val);  // Step 2: Root node
        inorder(root->right); // Step 3: Right subtree
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        for(int i=1;i<result.size();i++){
            if(result[i]<result[i-1]) return false;
        }
        return true;
    }
};