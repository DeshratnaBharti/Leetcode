class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val == p->val or root->val == q->val) return root;
        if(root->val >p->val and root->val <q->val) return root;
        else if(root->val <p->val and root->val >q->val) return root;
        else if(root->val <p->val and root->val <q->val) return lowestCommonAncestor(root->right,p,q);
        else return lowestCommonAncestor(root->left,p,q);
    }
};