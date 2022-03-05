// https://leetcode.com/problems/reorder-list/

class Solution {
public:
  ListNode* _middleOfList(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    
    return slow;
  }
  
  ListNode* _reveseList(ListNode* head) {
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
  
  void reorderList(ListNode* head) {
    /*OPTIMUM APPROACH
    TC: O(N/2 + N + N/2) = O(N)
    SC: O(1) */
    
    if(!head || !head->next || !head->next->next)
      return;
    
    ListNode* middle = _middleOfList(head);
    
    ListNode* h1, *h2, *t1, *t2;
    h1 = head;
    h2 = middle->next;
    middle->next = NULL;
    
    h2 = _reveseList(h2);
    
    while(h1 && h2) {
      t1 = h1->next;
      t2 = h2->next;
      
      h1->next = h2;
      h2->next = t1;
      
      h1 = t1;
      h2 = t2;
    }
  }
};