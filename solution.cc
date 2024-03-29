// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL, *prev = NULL;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                if(!head) head = l1;
                if(prev) prev->next = l1;
                prev = l1;
                l1 = l1->next;
            } else {
                if(!head) head = l2;
                if(prev) prev->next = l2;
                prev = l2;
                l2 = l2->next;
            }
        } 
        if(prev) {
            if(l1) prev->next = l1;
            if(l2) prev->next = l2;
            return head;
        }
        return l1 ? l1 : l2;
    }
};
