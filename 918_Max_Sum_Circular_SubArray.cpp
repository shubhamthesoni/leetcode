#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
      int len = nums.size();
      int maxSum = INT_MIN;
      int minSum = INT_MAX;
      int totalSum = 0;
      int maxCurr = 0;
      int minCurr = 0;
      for(int X: nums)
      {
        totalSum += X; maxCurr += X;  minCurr += X;
        maxSum = max(maxSum, maxCurr);
        minSum = min(minSum, minCurr);
        if(maxCurr < 0) maxCurr = 0;
        if(minCurr > 0) minCurr = 0;
      }

      return (totalSum == minSum) ? maxSum : max(maxSum, totalSum - minSum);
    }
};

int main()
{
  vector<int> V1 = { 1,-2, 3,-2};
  vector<int> V2 = { 5,-3, 5};
  vector<int> V3 = {-3,-2,-3};

  cout << Solution().maxSubarraySumCircular(V1) << endl;
  cout << Solution().maxSubarraySumCircular(V2) << endl;
  cout << Solution().maxSubarraySumCircular(V3) << endl;

  return 0;
}
