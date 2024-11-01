/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
     ListNode* reverseList(ListNode* head) {
        ListNode *prev =NULL,*curr = head,*nex =head;
        while(curr){
            nex = curr->next;
            curr->next =prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL and head->next == NULL) return true;
       ListNode* slow = head,*fast = head;
        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newhead = reverseList(slow->next);
        ListNode* a = head;
        ListNode* b = newhead;
    //    if ( a == NULL or b== NULL) return false;
        while(b  ){
            if( a->val != b->val) {return false;}
             a = a->next;
             b= b->next;
        }
        
        return true;
    }
};