#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
      bool ignoredOnce = false;
      int len = nums.size();
      for(int i = 0; i < len -2; i++)
      { 
        if(nums[i] >= nums[i+1])
        {
          if(ignoredOnce) return false;

          if((i > 0) && (i < len-2))
          {
            if((nums[i-1] < nums[i+1]) || (nums[i] < nums[i+2])) ignoredOnce = true;
            else return false;
          }
          else if(i > 0)
          {
            if(nums[i-1] < nums[i+1]) ignoredOnce = true;
            else if(nums[i-1] < nums[i]) ignoredOnce = true;
            else return false;
          }
          else
          {
            if(nums[i] < nums[i+2]) ignoredOnce = true;
            else if(nums[i+1] < nums[i+2]) ignoredOnce = true;
            else return false;
          }
        }
      }
      return true;
    }
};

int main()
{
  //vector<int> V = { 1,2,3,10,4,5};
  vector<int> V = { 1,2,9,10,4,5};

  Solution solution; 

  cout << solution.canBeIncreasing(V) << endl;
  return 0;
}
