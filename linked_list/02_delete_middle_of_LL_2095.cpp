// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

class Solution {
public:
  ListNode* deleteMiddle(ListNode* head) {
    /* OPTIMUM APPROACH
    TC: O(N)
    SC: O(1) */
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    ListNode* newHead = new ListNode(0, head);
    ListNode* slowPrev = newHead;
    
    while(fast && fast->next) {
      slowPrev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    
    slowPrev->next = slow->next;
    
    return newHead->next;
  }
};