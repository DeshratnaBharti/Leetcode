/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<vector<int>>res;
    void solve(Node* root,vector<int>&ans){
          if(root == nullptr) return;

        ans.push_back(root->data);
        if(root->left ==NULL and root->right==NULL){
          
            res.push_back(ans);
           
        }
       
        else{
        if(root->left != nullptr) solve(root->left,ans);
        if(root->right != nullptr) solve(root->right,ans);
        }
        ans.pop_back();
        
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<int>ans;
        solve(root,ans);
        return res;
    }
};