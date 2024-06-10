class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> R;
      int len = nums.size();

      function<void(int)>permute = [&](int s) {
        if(s == len)
        {
           R.push_back(nums);
           return;
        }

        for(int i = s; i < len; i++)
        {
          swap(nums[s], nums[i]);
          permute(s+1);
          swap(nums[i], nums[s]);
        }
        return;
      };

      permute(0);

      return R;        
    }
};
