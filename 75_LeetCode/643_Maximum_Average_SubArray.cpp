class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currSum = 0;
        double maxAverage = INT_MIN;
        int len = nums.size();
        for(int i = 0; i < k; i++) currSum += nums[i];
        maxAverage = currSum;

        int left = 0;
        for(int i = k; i < len; i++)
        {
            currSum += nums[i];
            currSum -= nums[left++];
            maxAverage = max(maxAverage, currSum);
        }
        return (double) maxAverage/k;
    }
};
