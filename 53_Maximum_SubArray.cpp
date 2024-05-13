#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int maxSum = INT_MIN;
      int currSum = 0;
      int len = nums.size(); 
      for(int i = 0; i < len; i++)
      {
        maxSum = max(maxSum, currSum = currSum + nums[i]);
        if(currSum < 0) { currSum = 0; }
      }
      return maxSum;
    }
};


int main()
{
  Solution solution;
  vector<int> V = { -2, 1,-3, 4,-1, 2, 1,-5, 4};
  cout << solution.maxSubArray(V) << endl;
  return 0;
}
