// https://leetcode.com/problems/palindrome-linked-list/

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
  
  bool isPalindrome(ListNode* head) {
    /* OPTIMUM APPROACH
    TC: O(N/2 + N + N/2) = O(N)
    SC: O(1) */
    
    if(!head)
      return false;
    
    ListNode* middle = _middleOfList(head);
    
    ListNode* c1 = head;
    ListNode* c2 = middle->next;
    middle->next = NULL;
    
    c2 = _reverseList(c2);
    
    while(c1 && c2) {
      if(c1->val != c2->val)
        return false;
      
      c1 = c1->next;
      c2 = c2->next;
    }
    
    return true;
  }
};