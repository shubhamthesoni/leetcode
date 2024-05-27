class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int start = 0;
        int len = nums.size();
        if(len == 0) return result;
        for(int i = 1; i < len; i++)
        {
            if(nums[i] == (nums[i-1] + 1)) continue;
            string S;
            if(start == i-1) S = to_string(nums[start]);
            else S = to_string(nums[start]) + "->" + to_string(nums[i-1]);
            result.push_back(S);
            start = i;
        }
        string S;
        if(start == (len-1)) S=to_string(nums[start]);
        else S = to_string(nums[start]) + "->" + to_string(nums[len-1]);
        result.push_back(S);
        return result; 
    }
};
