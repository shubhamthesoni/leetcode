class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
      int len = nums.size();
      if(len <= 1) return 0;

      sort(nums.begin(), nums.end());

      int inc = 0;
      int minValue = nums[0];
      for(int x: nums)
      {
        if(x < minValue) inc += (minValue - x);
        minValue = max(minValue+1, x+1);
      }
      return inc;
    }
};
