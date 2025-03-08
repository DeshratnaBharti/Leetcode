class Solution {
public:
    TreeNode* f(vector<int>& preorder, vector<int>& inorder,int start,int end,int& idx){
        if(start>end) return NULL;
        int rootval = preorder[idx];
        int i = start;
        for(;i<=end;i++){
            if(inorder[i]==rootval) break;
        }
        idx++;
        TreeNode* root = new TreeNode(rootval);
        root->left = f(preorder,inorder,start,i-1,idx);
        root->right = f(preorder,inorder,i+1,end,idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n= inorder.size();
        int idx=0;
        return f(preorder,inorder,0,n-1,idx);
    }
};