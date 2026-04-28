/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Function to return a list containing the level order traversal in spiral form.
class Solution {
  public:
    int sumBT(Node* root) {
        // code here
        queue<Node*>que;
        que.push(root);
        int s = 0;
        while(!que.empty()){
            Node* node = que.front();
            que.pop();
            
             s = s + node->data;
            if(node->left != NULL) que.push(node->left);
            if(node->right != NULL) que.push(node->right);
        }
        return s;
    }
};