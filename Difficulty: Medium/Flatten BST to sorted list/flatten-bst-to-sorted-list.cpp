class Solution {
  public:
    Node* flattenBST(Node* root) {
        if (!root) return nullptr;

        Node* leftList = flattenBST(root->left);
        Node* rightList = flattenBST(root->right);

        root->left = nullptr;
        root->right = rightList;

        if (!leftList) return root;

        Node* temp = leftList;
        while (temp->right) {
            temp = temp->right;
        }
        temp->right = root;

        return leftList;
    }
};
