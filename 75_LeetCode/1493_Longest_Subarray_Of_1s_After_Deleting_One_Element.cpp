#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k = 1;
        int currCount = 0;
        int maxCount = INT_MIN;

        int len = nums.size();
        int start = 0;
        for(int i = 0; i < len; i++)
        {
          if(nums[i] == 0) k--;
          if(k < 0)
          {
            if(nums[start] == 0) k++;
            start++;
          }
          maxCount = max(maxCount, i - start + 1 - 1);
        } 
        return maxCount;
    }
};

int main()
{
  vector<int> V = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1};
  cout << Solution().longestSubarray(V) << endl;
  return 0;
}
