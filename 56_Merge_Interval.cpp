#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      vector<vector<int>> result;
      sort(intervals.begin(), intervals.end());
      //return intervals;
      int len = intervals.size();
      if(len <= 1) return intervals;
      result.push_back(intervals[0]);
      for(int i = 1; i < len ; i++)
      {
        if(result.back()[1] >= intervals[i][0])
        {
          if(result.back()[1] > intervals[i][1]) continue;
            result.back()[1] = intervals[i][1];
        }
        else
        {
          result.push_back(intervals[i]);
        } 
      }

#if 0
      int i = 1;
      while(i <= len)
      {
        for(; i < len; i++)
        {
          if(intervals[i][0] > intervals[i-1][1]) { result.push_back({intervals[i-1][0], intervals[i-1][1]}); continue; }
          break;
        }

        if(i == len) { result.push_back({intervals[len-1][0], intervals[len-1][1]}); break; }

        int start = intervals[i-1][0];
        int end = max(intervals[i-1][1], intervals[i][0]);

        for(; i < len; i++)
        {
          if(intervals[i][0] <= end) { end = max(end, intervals[i][1]); continue;}
          break;
        }
        i++;
        result.push_back({start, end});
        cout << i << endl;
      }
#endif
      return result;        
    }
};


int main()
{
  vector<vector<int>> V = {{1,3}, {5,5}, {2,2}, {3,4}, {3,4}};
  V = Solution().merge(V);
  for(vector<int> R : V)
  {
    cout << "{"<<R[0]<<","<<R[1]<<"}, ";
  }
  cout << endl;
  return 0;
}
