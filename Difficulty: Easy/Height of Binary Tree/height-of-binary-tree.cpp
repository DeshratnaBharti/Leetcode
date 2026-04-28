/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int height(Node* root) {
        // code here
        queue<Node*>que;
        que.push(root);
        int count =0;
        while(!que.empty()){
            int n = que.size();
            while(n--){
                Node* node = que.front();
                que.pop();
                if(node->left != NULL) que.push(node->left);
                if(node->right != NULL) que.push(node->right);
                
            }
            count++;
        }
        return count-1;
    }
};