// https://leetcode.com/problems/arithmetic-slices/

class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    /* NAIVE APPROACH
    TC: O(N*N)
    SC: O(1)
    
    if(nums.size() < 3)
      return 0;
        
    int ans = 0, diff;

    for(int i = 0; i < nums.size() - 2; i++) {
      diff = nums[i+1] - nums[i];

      for(int j = i+2; j<nums.size(); ++j) {
        if(nums[j] - nums[j-1] == diff)
          ans++;
        else
          break;
      }
    }
    
    return ans; */
    
    /* OPTIMUM APPROACH
    TC: O(N)
    SC: O(N) */
    
    int ans = 0;
    vector<int> dp(nums.size());
    // int dp[nums.size()];
    
    for(int i = 2; i < nums.size(); i++) {
      if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
        dp[i] = dp[i-1] + 1;
        ans += dp[i];
      }
    }
    return ans;
  }
};