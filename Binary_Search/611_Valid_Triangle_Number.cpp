class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int len = nums.size();
        if(len <= 2) return 0;
        sort(nums.begin(), nums.end());
        int count = 0;
        
        for(int i = 0; i < len; i++)
        {
            int low = 0;
            int high = i-1;
            while(low < high)
            {
                if((nums[low] + nums[high]) > nums[i]) { count += (high - low); high--;}
                else low++;
            }
        }
        return count;
    }
};
