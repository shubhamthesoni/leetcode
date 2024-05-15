#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minJump(vector<int>& nums, int len, int index)
    {
      int result = INT_MAX;
      if((index + 1 + nums[index]) >= len) return 1;
      for(int i = 1; i < nums[index] ; i++)
      {
        result = min(result, minJump(nums, len, index + i));
      }
      return result + 1;
    }

    int jump(vector<int>& nums) {
      int len = nums.size();
      int result = INT_MAX;
      if((nums[0]+1) >= len) return 1;
      for(int i = 1; i < nums[0]; i++)
      {
        result = min(result, minJump(nums, len, i));
      }
      return result + 1;
    }
};


int main()
{
  vector<int> V = {1,2,3};
  cout << Solution().jump(V) << endl;
  return 0;
}

