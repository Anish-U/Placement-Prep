// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class Solution {
public:
  int _findLength(ListNode* head) {
    int len = 0;
    while(head) {
      len++;
      head = head->next;
    }
    return len;
  }
  
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    /* NAIVE APPROACH
    TC: O(N) + O(N) = O(N)
    SC: O(1)
    
    ListNode* newHead = new ListNode(0, head);
    ListNode* temp = newHead;
    int len = _findLength(head);
    
    for(int i = 0; i < len - n; i++)
      temp = temp->next;
    
    temp->next = temp->next->next;
    
    return newHead->next; */
    
    /* OPTIMUM APPROACH
    TC: O(N)
    SC: O(1) */
    
    ListNode* newHead = new ListNode(0, head);    
    ListNode* fast = newHead;
    ListNode* slow = newHead;
    
    for(int i = 0; i < n; i++)
      fast = fast->next;
    
    while(fast->next) {
      slow = slow->next;
      fast = fast->next;
    }
    
    slow->next = slow->next->next;
    
    return newHead->next;
  }
};