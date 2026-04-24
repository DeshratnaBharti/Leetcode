/*
class Node {
   public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
} */

class Solution {
  public:
    bool detectLoop(Node* head) {
        // code here
        Node* s = head;
        Node* f = head;
        while(  f->next != NULL and f->next->next !=NULL){
            f= f->next->next;
            s = s->next;
            if(f==s) return true;
        }
        return false;
        
    }
};