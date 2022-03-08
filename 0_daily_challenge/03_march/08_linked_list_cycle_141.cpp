// https://leetcode.com/problems/linked-list-cycle/

class Solution {
public:
  bool hasCycle(ListNode *head) {
    /* NAIVE APPROACH
    TC: O(N)
    SC: O(N)
    
    if(!head || !head->next)
      return false;
    
    set<ListNode*> nodeSet;
    ListNode* curr = head;
    
    while(curr) {
      if(nodeSet.find(curr) != nodeSet.end())
        return true;
      
      nodeSet.insert(curr);
      curr = curr->next;
    }
    
    return false; */
    
    /* OPTIMUM APPROACH
    TC: O(N)
    SC: O(1) */
    
    if(!head || !head->next)
      return false;
    
    ListNode* slow = head;
    ListNode* fast = head->next;
    
    while(fast->next && fast->next->next) {
      if(slow == fast)
        return true;
      
      slow = slow->next;
      fast = fast->next->next;
    }
    
    return false;
  }
};