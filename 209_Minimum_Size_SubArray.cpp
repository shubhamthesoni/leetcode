#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int len = nums.size();
      int start = 0;
      int curr_sum = 0;
      int minSize = INT_MAX;

      for(int i = 0; i < len ; i++)
      {
        curr_sum += nums[i];
        if(curr_sum >= target) 
        {
          while((curr_sum - nums[start]) >= target) { curr_sum -= nums[start++]; } 
          //curr_sum = 0; 
          minSize = min(minSize, (i - start + 1)); 
          //start = i+1; 
        }
      }

      return (minSize == INT_MAX) ? 0:minSize;
    }
};

int main()
{
  vector<int> V1 = { 2,3,1,2,4,3};
  vector<int> V2 = { 10,5,13,4,8,4,5,11,14,9,16,10,20,8};
  cout << Solution().minSubArrayLen(7, V1) << endl;
  cout << Solution().minSubArrayLen(80, V2) << endl;
  return 0;
}
