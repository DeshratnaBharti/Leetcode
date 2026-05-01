/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    bool isIdentical(Node* r1, Node* r2) {
        if(r1==NULL and r2==NULL) return true;
        if(r1 == NULL || r2 == NULL) return false;
        if(r1->data != r2->data) return false;
        bool a = isIdentical(r1->left,r2->left);
        bool b = isIdentical(r1->right,r2->right);
        return a and b;
    }
};