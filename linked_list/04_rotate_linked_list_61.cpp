// https://leetcode.com/problems/rotate-list/

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
  
  ListNode* rotateRight(ListNode* head, int k) {
    /* 3 STEP APPROACH
    TC: O(N) + O(N-K) + O(K) = O(N)
    SC: O(1) 

    if(!head || !head->next)
      return head;
    
    int len = _findLength(head);
    k = k % len;
    
    if(!k)
      return head;
    
    ListNode* newHead = new ListNode(0, head);
    ListNode* curr = head;
    
    for(int i = 0; i < len - k - 1; i++)
      curr = curr->next;
    
    newHead->next = curr->next;
    ListNode* temp = curr->next;
    curr->next = NULL;
    
    while(temp->next)
      temp = temp->next;
    
    temp->next = head;
    
    return newHead->next; */
    
    /* REVERSAL ALGO APPROACH
    TC: O(N-K) + O(K) + O(N)
    SC: O(1) */
    
    if(!head || !head->next)
      return head;
    
    int len = _findLength(head);
    k = k % len;
    
    if(!k)
      return head;
    
    ListNode* head1 = head;
    ListNode* temp = head;
    ListNode* head2;
    
    for(int i = 0; i < len - k - 1; i++)
      temp = temp->next;
    
    head2 = temp->next;
    temp->next = NULL;
    
    head1 = _reverseList(head1);
    head2 = _reverseList(head2);
    temp = head1;
    
    while(temp->next)
      temp = temp->next;
    
    temp->next = head2;
    
    head = _reverseList(head1);
    
    return head;
    
  }
};