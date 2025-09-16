class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev1 = dummy;
        ListNode* curr1 = head;

        
        for (int i = 1; i < left; i++) {
            prev1 = curr1;
            curr1 = curr1->next;
        }

        
        ListNode* prev = nullptr;
        ListNode* curr = curr1;
        for (int i = 0; i <= right - left; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

       
        prev1->next->next = curr; 
        prev1->next = prev;       
        return dummy->next;
    }
};
