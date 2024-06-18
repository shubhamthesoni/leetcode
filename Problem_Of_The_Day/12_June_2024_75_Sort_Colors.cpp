class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int zero = 0;
        int two = len-1;
        for(int i = 0; i <= two; i++)
        {
            if(nums[i] == 2) 
            { 
                nums[i] = nums[two];
                nums[two--] = 2;
                i--;
            }
            else if(nums[i] == 0)
            {
                nums[i] = nums[zero];
                nums[zero++] = 0;
            }
        }
        return;
    }
};
