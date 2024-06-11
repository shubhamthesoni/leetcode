#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int len = nums.size();
      int non_zero = 0;
      for(int i = 0; i < len; i++)
      {
        if(nums[i] == 0) continue;
        nums[non_zero++] = nums[i];  
      }
      for(int i = non_zero; i < len; i++) nums[i] = 0;
    }
};
