
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head ==NULL or head->next==NULL) return head;
      ListNode* temp = head;
      int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        temp = head;
        int n = count/2;
        int i=0;
        while(temp and  i<n){
            temp =temp->next;
            i++;
        }
        return temp;
    }
};