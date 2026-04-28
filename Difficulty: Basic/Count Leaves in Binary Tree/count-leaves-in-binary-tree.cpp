/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        // write code here
        queue<Node*>que;
        que.push(root);
        int count =0;
        while(!que.empty()){
            Node* node = que.front();
            que.pop();
            if(node->left == NULL and node->right == NULL) count++;
            if(node->left != NULL ) que.push(node->left);
            if(node->right != NULL) que.push(node->right);
            
        }
        return count;
    }
};