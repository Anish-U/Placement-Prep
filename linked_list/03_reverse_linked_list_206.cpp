// https://leetcode.com/problems/reverse-linked-list/

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    /* ITERATIVE APPROACH
    TC: O(N)
    SC: O(1)
    
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* nxt;
    
    while(curr) {
      nxt = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nxt;
    }
    
    return prev; */
    
    /* RECURSIVE APPROACH
    TC: O(N)
    SC: O(1) */
    
    if(!head || !head->next)
      return head;
    
    ListNode* newHead = reverseList(head->next);
    
    head->next->next = head;
    head->next = NULL;
    
    return newHead;
  }
};