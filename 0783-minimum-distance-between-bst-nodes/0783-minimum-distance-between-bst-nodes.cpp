
class Solution {
public:
    int minDiff=INT_MAX;
    void inord(TreeNode* root,TreeNode* &prev){
        if(!root) return ;
        inord(root->left,prev);
        if(prev!=NULL){
            minDiff = min(minDiff,abs(root->val- prev->val));
        }
        prev = root;
        inord(root->right,prev);
    }
    int minDiffInBST(TreeNode* root) {
        TreeNode* prev = NULL;
        inord(root,prev);
        return minDiff;
    }
};