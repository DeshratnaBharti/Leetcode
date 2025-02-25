class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL and q ==NULL) return true;
         if(p==NULL and q !=NULL) return false; 
         if(p!=NULL and q ==NULL) return false;
        //root ki value same na ho
        if(p->val != q->val) return false;

         bool leftAns = isSameTree(p->left,q->left);
         if(leftAns==false) return false;
         
         bool rightAns = isSameTree(p->right,q->right);
         if(rightAns==false) return false;
         return true;

    }
};