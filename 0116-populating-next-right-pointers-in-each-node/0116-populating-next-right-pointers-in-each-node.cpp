class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        queue<Node*> q;
        q.push(root);
        q.push(nullptr);  // level marker

        Node* prev = nullptr;

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr == nullptr) {
                prev = nullptr;
                if (!q.empty()) q.push(nullptr);
            } else {
                if (prev) prev->next = curr;
                prev = curr;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }

        return root;
    }
};
