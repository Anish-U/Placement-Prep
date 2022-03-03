// https://leetcode.com/problems/middle-of-the-linked-list/

class Solution {
public:
  ListNode* middleNode(ListNode* head) {
    /* NAIVE APPROACH
    TC: O(N + N/2) = O(N)
    SC: O(1)
    
    ListNode* temp = head;
    int len = 0;
    
    while(temp) {
      len++;
      temp = temp->next;
    }
    
    temp = head;
    for(int i = 0; i < len / 2; i++)
      temp = temp->next;
    
    return temp; */
    
    /* OPTIMUM APPROACH
    TC: O(N/2) = O(N)
    SC: O(1) */
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    
    return slow;
  }
};