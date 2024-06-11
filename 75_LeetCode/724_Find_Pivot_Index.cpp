class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        vector<int> DP(len, 0);
        int sum = 0;
        for(int i = len-1; i >= 0; i--)
        {
            DP[i] = sum;
            sum += nums[i];
        }
        sum = 0;
        for(int i = 0; i < len; i++)
        {
            //cout << DP[i] << " " << sum <<endl;
            if(DP[i] == sum) return i;
            sum += nums[i];
        }
        return -1;
    }
};
