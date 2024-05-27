class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> M;
        int len = nums.size();
        for(int i = 0; i < len; i++)
        {
          if(M[nums[i]] > 0) return true;
          if(i >= k) M[nums[i-k]]--;
          M[nums[i]]++;
        }
        return false;
    }
};
