// https://leetcode.com/problems/swap-nodes-in-pairs/

class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    /* OPTIMUM APPROACH
    TC: O(N)
    SC: O(1) */

    if(!head || !head->next)
      return head;
    
    ListNode* newHead = new ListNode(0, head);
    ListNode* prev = newHead;
    ListNode* curr = head;
    
    while(curr && curr->next) {
      prev->next = curr->next;
      curr->next = prev->next->next;
      prev->next->next = curr;
      
      prev = curr;
      curr = curr->next;
    }
    
    return newHead->next; 
  }
};