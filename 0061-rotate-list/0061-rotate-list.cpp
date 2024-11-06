
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL or head->next==NULL) return head;
        ListNode* temp = head;
        ListNode* tail =NULL;
        int len=0;
        while(temp){
            if(temp->next == NULL) tail = temp;
            temp=temp->next;
            len++;
        }
        k=k%len;
        if(k==0) return head;
        temp =head;
        for(int i=1;i<len-k;i++){
            temp= temp->next;
        }
        tail->next=head;
        head = temp->next;
        temp->next=NULL;
        return head;
    }
};