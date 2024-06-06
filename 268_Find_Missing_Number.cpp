class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = nums.size();
        sum = (sum * (sum+1))/2;
        sum -= accumulate(nums.begin(), nums.end(), 0);
        return sum;
    }
};
