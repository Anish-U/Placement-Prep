// https://leetcode.com/problems/partition-list/

class Solution {
public:
  ListNode* partition(ListNode* head, int x) {
    /* OPTIMUM APPROACH
    TC: O(N)
    SC: O(1) */
    
    ListNode* temp = head;

    ListNode* lHead = new ListNode();
    ListNode* lPrev = lHead;
    ListNode* rHead = new ListNode();
    ListNode* rPrev = rHead;
    
    while(temp) {
      if(temp->val >= x) {
        rPrev->next = temp;
        rPrev = rPrev->next;
      }
      else {
        lPrev->next = temp;
        lPrev = lPrev->next;
      }
      temp = temp->next;
    }

    rPrev->next = NULL;
    lPrev->next = rHead->next;

    return lHead->next;
  }
};