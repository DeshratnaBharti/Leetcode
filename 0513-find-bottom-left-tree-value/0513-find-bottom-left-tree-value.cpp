
class Solution {
public:
    int maxi = INT_MIN,leftM=0;
    void f(TreeNode* p,int level){
        if(p==NULL) return ;
        if(maxi<level){
            maxi = level;
            leftM = p->val;

        }
        f(p->left,1+level);
        f(p->right,1+level);
        
    }
    int findBottomLeftValue(TreeNode* root) {
        f(root,1);
        return leftM;
    }
};