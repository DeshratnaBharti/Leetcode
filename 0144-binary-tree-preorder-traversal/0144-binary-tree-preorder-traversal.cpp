
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
          vector<int> preorder;
        
        // If the root is null, return
        // an empty traversal result
        if(root == nullptr) {
            return preorder;
        }
        
        // Create a stack to store
        // nodes during traversal
        stack<TreeNode*> st;
        // Push the root node
        // onto the stack
        st.push(root);
        
        // Perform iterative preorder traversal
        while(!st.empty()) {
            // Get the current node
            // from the top of the stack
            root = st.top();
            // Remove the node
            // from the stack
            st.pop();
            
            // Add the node's value to
            // the preorder traversal result
            preorder.push_back(root->val);
            
            // Push the right child
            // onto the stack if exists
            if(root->right != nullptr) {
                st.push(root->right);
            }
            
            // Push the left child onto
            // the stack if exists
            if(root->left != nullptr) {
                st.push(root->left);
            }
        }
        
        // Return the preorder
        // traversal result
        return preorder;
    }
};