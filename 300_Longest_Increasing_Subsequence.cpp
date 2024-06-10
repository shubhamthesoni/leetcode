class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> DP;
        DP.push_back(nums[0]);
        for(int i = 1; i < len; i++)
        {
            if(nums[i] > DP.back())
            {
                DP.push_back(nums[i]);
            }
            else
            {
                int index = lower_bound(DP.begin(), DP.end(), nums[i]) - DP.begin();
                DP[index] = nums[i];
            }
        }
        return DP.size();
    }
};
