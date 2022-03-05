// https://leetcode.com/problems/delete-and-earn/

class Solution {
public:
  int dp[20001];
  
  int _helper(vector<int> &nums, int id) {
    if(id >= nums.size())
      return 0;
    
    if(dp[id] != -1)
      return dp[id];
    
    int currVal = nums[id];
    int currSum = nums[id];
    int idx = id + 1;
    
    while(idx < nums.size() && nums[idx] == currVal) {
      currSum += currVal;
      idx++;
    }
    
    while(idx < nums.size() && nums[idx] == currVal + 1)
      idx++;
    
    return dp[id] = max(currSum + _helper(nums, idx), _helper(nums, id + 1));
  }
  
  int deleteAndEarn(vector<int>& nums) {
    /*NAIVE APPROACH
    TC: O(NlogN + N) = O(NlogN)
    SC: O(N) */
    
    memset(dp, -1, sizeof(dp));
    
    sort(nums.begin(), nums.end());
    
    return _helper(nums, 0);
  }
};