// https://leetcode.com/problems/add-two-numbers/

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    /* OPTIMUM APPROACH
    TC: O(N)
    SC: O(N) */
    ListNode* c1 = l1;
    ListNode* c2 = l2;
    ListNode* newHead = new ListNode();
    ListNode* prev = newHead;
    
    int sum = 0;
    int carry = 0;
    
    while(c1 || c2 || carry) {
      sum = carry;
      if(c1) {
        sum += c1->val;
        c1 = c1->next;
      }
      if(c2) {
        sum += c2->val;
        c2 = c2->next;
      }
      
      prev->next = new ListNode(sum % 10);
      prev = prev->next;
      carry = sum / 10;
    }
    
    return newHead->next;
  }
};