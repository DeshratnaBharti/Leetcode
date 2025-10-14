
class Solution {
public:
    bool f(TreeNode* p,TreeNode* subRoot){
        if(p==nullptr and subRoot==nullptr) return true;
        if((p == nullptr) || (subRoot == nullptr)) return false;
          if (p->val != subRoot->val) return false;
        return f(p->left,subRoot->left) and f(p->right,subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) return false;
    if (f(root, subRoot)) return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

    }
};