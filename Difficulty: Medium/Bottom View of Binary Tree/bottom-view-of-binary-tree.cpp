/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  vector<int>res;
    void solve(map<int,int>&mp,Node* root){
        if(root==nullptr) return  ;
        queue<pair<int,Node*>>que;
        que.push({0,root});
        while(!que.empty()){
            auto curr = que.front();
            que.pop();
            int index = curr.first;
            Node* a = curr.second;
            
                    mp[index] = a->data;
                
            if(a->left != NULL){
                que.push({index-1,a->left});
                
            }
            if(a->right != NULL) que.push({index+1,a->right});
        }
        for(auto &a:mp){
            res.push_back(a.second);
        }
        
    }
    vector<int> bottomView(Node *root) {
        // code here
        map<int,int>mp;
       solve(mp,root);
        return res;
    }
};