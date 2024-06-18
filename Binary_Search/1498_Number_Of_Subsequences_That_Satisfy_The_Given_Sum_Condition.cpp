class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
      int MOD = 1e9 + 7;
      sort(nums.begin(), nums.end());
      int len = nums.size();
      vector<int> POW(len + 1, 1);
      for(int i = 1; i <= len ; i++) POW[i] = (POW[i-1]*2)%MOD;
      int count = 0;
      for(int i = 0; i < len; i++)
      {
        if((nums[i] * 2L) > target) break;
        int j = upper_bound(nums.begin() + i + 1, nums.end(), target - nums[i]) - nums.begin() - 1;
        count = (count + POW[j - i]) % MOD;
      }
      return count;
    }
};

