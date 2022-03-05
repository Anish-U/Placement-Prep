// https://leetcode.com/problems/odd-even-linked-list/

class Solution {
public:
  ListNode* oddEvenList(ListNode* head) {
    /*NAIVE APPROACH
    TC: O(N)
    SC: O(1)
    
    ListNode* temp = head;
    
    ListNode* oddHead = new ListNode();
    ListNode* oddPrev = oddHead;
    ListNode* evenHead = new ListNode();
    ListNode* evenPrev = evenHead;
    
    bool odd = true;
    
    while(temp) {
      if(odd) {
        oddPrev->next = temp;
        oddPrev = oddPrev->next;
      }
      else {
        evenPrev->next = temp;
        evenPrev = evenPrev->next;
      }
      temp = temp->next;
      odd = !odd;
    }
    
    evenPrev->next = NULL;
    oddPrev->next = evenHead->next;
    
    return oddHead->next; */
    
    /* OPTIMUM APPROACH
    TC: O(N)
    SC: O(1) */
    
    if(!head || !head->next || !head->next->next) 
      return head;
    
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenStart = head->next;

    while(odd->next && even->next) {
      odd->next = even->next;
      even->next = odd->next->next;
      
      odd = odd->next;
      even = even->next;
    }
    
    odd->next = evenStart;
    return head; 
  }
};