
class Solution {
public:
    int maxSum;
    int solve(TreeNode* root){
        if(root==NULL) return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        int neeche_hi_milega = l+r+root->val;
        int koi_ek_accha = max(l,r)+root->val;
        int only_root_accha = root->val;
        maxSum = max({maxSum,neeche_hi_milega,koi_ek_accha,only_root_accha});
        return max(koi_ek_accha,only_root_accha);

    }
    int maxPathSum(TreeNode* root) {
        maxSum =INT_MIN;
        solve(root);
        return maxSum;
        
    }
};