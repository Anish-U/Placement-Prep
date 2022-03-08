// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

class Solution {
public:
  
  ListNode* _middleOfList(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev;
    while(fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    return prev;
  }
  
  ListNode* _reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* nxt;
    while(curr) {
      nxt = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nxt;
    }
    return prev;
  }
  
  int pairSum(ListNode* head) {
    /* OPTIMUM APPROACH
    TC: O(N)
    SC: O(1) */
    
    int ans = -99;
    
    ListNode* middle = _middleOfList(head);
    
    ListNode* c1 = head;
    ListNode* c2 = middle->next;
    middle->next = NULL;
    
    c2 = _reverseList(c2);
    
    while(c1 && c2) {
      ans = max(ans, c1->val + c2->val);
      c1 = c1->next;
      c2 = c2->next;
    }
    
    return ans;
  }
};