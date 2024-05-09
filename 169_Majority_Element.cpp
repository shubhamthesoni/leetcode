class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> hash;
        int len = nums.size();
        for(int i = 0; i < len; i++)
        {
            hash[nums[i]]++;
            if(hash[nums[i]] > (len/2)) return nums[i];
        }
        return -1;
    }
};
