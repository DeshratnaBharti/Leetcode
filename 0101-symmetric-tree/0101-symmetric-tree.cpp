
class Solution {
public:
    bool isM(TreeNode* n1,TreeNode* n2){
        if(n1==NULL and n2==NULL) return true;
        if(n1==NULL or n2==NULL) return false;
        if(n1->val != n2->val) return false;
        return isM(n1->left,n2->right) and isM(n1->right,n2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isM(root->left,root->right);
    }
};