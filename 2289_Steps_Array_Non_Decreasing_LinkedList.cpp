#include <iostream>
#include <vector>
#include <climits>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int totalSteps(vector<int>& nums) 
    {
      int len = nums.size(), result = 0;
      stack<pair<int, int>> S;
      S.push({nums[len-1], 0});
      for(int i = len-2; i >= 0; i--)
      {
        result = 0;
        while(!S.empty() && S.top().first < nums[i] )
        {
          result = max(result+1, S.top().second);
          S.pop();
        }
        S.push({nums[i], result});
      }

      result = 0;
      while(!S.empty()) { result = max(result, S.top().second); S.pop(); }

      return result;
    }
};


int main()
{
  Solution solution;
  vector<int> V = {19,1,2,3,4,5,6,1,2,3,4,8,9,10,11};
  cout << solution.totalSteps(V);
  cout << endl;

  return 0;
}
