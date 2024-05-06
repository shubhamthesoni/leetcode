#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <set>

using namespace std;


class Solution {
public:
    int findMaxK(vector<int>& nums) {
      set<int> M;
      int result = -1;
      for(int i = 0; i < nums.size(); i++)
      {
        if(M.find(0-nums[i])!= M.end())
        {
          result = max(result, abs(nums[i]));
        }
        M.insert(nums[i]);
      }
      return result;     
    }
};

int main()
{
  Solution solution;
  vector<int> N = {-1, 2, 3, -3};
  cout << solution.findMaxK(N);
  return 0;
}
