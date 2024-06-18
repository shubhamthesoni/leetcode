class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long  maxP = 1;
        int count = 0;
        int index = 0;
        int len = nums.size();
        while(maxP <= n)
        {
            if((index < len) && (maxP >= nums[index]))
            {
                maxP += nums[index++];
            }
            else
            {
                maxP += maxP;
                count++;
            }
        }
        return count;
    }
};
