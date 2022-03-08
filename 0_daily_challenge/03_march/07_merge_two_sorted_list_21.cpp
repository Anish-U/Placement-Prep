// https://leetcode.com/problems/merge-two-sorted-lists/

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    /* OPTIMUM APPROACH
    TC: O(N+M)
    SC: O(N+M) */
    
    ListNode* newHead = new ListNode();
    ListNode* prev = newHead;
    ListNode* c1 = list1;
    ListNode* c2 = list2;
    
    while(c1 && c2) {
      if(c1->val > c2->val) {
        prev->next = c2;
        c2 = c2->next;
      }
      else {
        prev->next = c1;
        c1 = c1->next;
      }
      prev = prev->next;
    }
    
    if(c1) {
      prev->next = c1;
    }
    else {
      prev->next = c2;
    }
    
    return newHead->next;
    
  }
};