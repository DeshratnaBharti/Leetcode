
class Solution {
public: 
     vector<int> result;
     void inorder(TreeNode* root) {
        if (root == nullptr) return;

        inorder(root->left);   
        result.push_back(root->val);  
        inorder(root->right); 
    }
    bool isValidBST(TreeNode* root) {
         
        inorder(root);

        
        for (int i = 1; i < result.size(); i++) {
            if (result[i] <= result[i - 1]) { 
                return false;
            }
        }
        return true;
    }
};