#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& intervals) {
      vector<vector<int>> result;
      sort(intervals.begin(), intervals.end());
      int len = intervals.size();
      result.push_back(intervals[0]);
      for(int i = 1; i < len ; i++)
      {
        if(result.back()[1] >= intervals[i][0])
        {
          result.back()[1] = min(result.back()[1], intervals[i][1]);
          result.back()[0] = max(result.back()[0], intervals[i][0]);
        }
        else
        {
          result.push_back(intervals[i]);
        }
      }
      return result.size();
    }
};

int main()
{
  vector<vector<int>> V = {{10,16},{2,8},{1,6},{7,12}};
  cout << Solution().findMinArrowShots(V) << endl;
  return 0;
}
