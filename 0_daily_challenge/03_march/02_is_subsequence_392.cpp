// https://leetcode.com/problems/is-subsequence/

class Solution {
public:
  
  bool isSubsequence(string s, string t) {
    /* NAIVE APPROACH
    TC: O(N + M)
    SC: O(1)
    
    int j = 0;
    for(int i = 0; i < t.size() && j < s.size(); i++) {
      if(s[j] == t[i])
        j++;
		} 
    return j == s.size(); */
    
    /* RECURSIVE APPROACH
    TC: O(N + M)
    SC: O(1) */
		
    if(s.size() == 0)
      return true;
    if(t.size() == 0)
      return false;
    if(s[0] == t[0])
      return isSubsequence(s.substr(1), t.substr(1));
    else
      return isSubsequence(s,t.substr(1));
  }
};