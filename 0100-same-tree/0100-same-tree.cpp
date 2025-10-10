
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;

        
        if (p == nullptr || q == nullptr) return false;
       
       
        if(p->val != q->val) return false;
        bool a= isSameTree(p->left,q->left);
        bool b = isSameTree(p->right,q->right);
        return a and b;
    }
};