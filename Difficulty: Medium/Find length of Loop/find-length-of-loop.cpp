/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node* s = head;
        Node* f = head;
        bool flag = false;
        while(f != NULL and f->next != NULL){
            f = f->next->next;
            s = s->next;
            if(s==f) {
                flag = true;
                break;
            }
        }
        if(flag == false) return 0;
        s = s->next;
        int l =1;
        while(s!=f){
            s = s->next;
            l++;
        }
        return l;
    }
};