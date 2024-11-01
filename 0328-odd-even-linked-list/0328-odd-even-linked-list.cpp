class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL or head->next ==NULL) return head;
        ListNode* odd =head;
        ListNode* even = head->next;
        ListNode* newhead =even;
        while(even and even->next){
            odd->next= even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
        }
        odd->next=newhead;
        return head;
    }
};