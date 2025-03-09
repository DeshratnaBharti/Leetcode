class Solution {
public:
    TreeNode* f(vector<int>& inorder, vector<int>& postorder,int inS,int inE,int poS,int poE){
        if(inS>inE) return NULL;
        TreeNode* root = new TreeNode(postorder[poE]);
        int i = inS;
        for(;i<=inE;i++){

            if(inorder[i]==root->val) break;
        }
        int leftS=i-inS;
        int rightS=inE-i;

        root->left = f(inorder,postorder,inS,i-1,poS,poS+leftS-1);
        root->right = f(inorder,postorder,i+1,inE,poE-rightS,poE-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int inS=0;
        int inE =n-1;
        int poS =0;
        int poE=n-1;

        return f(inorder,postorder,inS,inE,poS,poE);
    }
};