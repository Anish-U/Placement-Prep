// https://leetcode.com/problems/counting-bits/

class Solution {
public:
  vector<int> ans;
  
  vector<int> countBits(int n) {
    ans = vector<int>(n + 1, 0);
    
    /* NAIVE APPROACH
    TC: O(NlogN) 
    SC: O(1)
    
    for(int i = 1; i <= n; i++) {
      int ones = 0;
      int num = i;
      
      while (num > 0) {
        ones += num % 2;
        num = num / 2;
      }
      
      ans[i] = ones;
    } 
    */
    
    /* OPTIMUM APPROACH
    TC: O(N)
    SC: O(1) 
    Refer: https://youtu.be/iuqr5hHk2MI */
    
    for(int i = 1; i <= n; i++) {
      ans[i] = ans[i >> 1] + i % 2;
    }
    return ans;
  }
};