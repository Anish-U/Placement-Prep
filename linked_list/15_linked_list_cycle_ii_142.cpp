// https://leetcode.com/problems/linked-list-cycle-ii/

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    /* NAIVE APPROACH
    TC: O(N)
    SC: O(N)
    
    if(!head || !head->next)
      return NULL;
    
    set<ListNode*> nodeSet;
    ListNode* curr = head;
    
    while(curr) {
      if(nodeSet.find(curr) != nodeSet.end())
        return curr;
      
      nodeSet.insert(curr);
      curr = curr->next;
    }
    
    return NULL; */
    
    /* OPTIMUM APPROACH
    TC: O(N)
    SC: O(1) */
    
    if(!head || !head->next)
      return NULL;
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;

      if(slow == fast){ 
        slow = head;
        while(slow != fast) {
          slow = slow->next; 
          fast = fast->next; 
        }
        return slow;
      }
    }
    
    return NULL;
  }
};