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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* d = head;
        ListNode *curr = head;
        ListNode *f = head;
        while(curr != NULL){
            while(curr->next != NULL and curr->val == curr->next->val){
                curr = curr->next;
            }
            curr = curr->next;
            f->next = curr;
            f = f->next;
        }
        return d;
        
    }
};