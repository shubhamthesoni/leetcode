#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       int i = 0;
       int len = intervals.size();
       vector<vector<int>> R;

       while(i<len && intervals[i][1] < newInterval[0]) R.push_back(intervals[i++]);
   
       while(i<len && intervals[i][0] <= newInterval[1]) { 
         newInterval[0] = min(newInterval[0], intervals[i][0]);
         newInterval[1] = max(newInterval[1], intervals[i][1]);
         i++;
       }
       R.push_back(newInterval);

       while(i < len) R.push_back(intervals[i++]);

       return R;
    }
};

int main()
{
  Solution solution;
  vector<vector<int>> I = {{1,2},{3,4},{6,7},{9,10},{12,16}};
  vector<int> N = {5,6};

  vector<vector<int>> R = Solution().insert(I, N);
  for(int i = 0; i < R.size(); i++)
    cout << "{"<<R[i][0]<<","<<R[i][1]<<"}, ";

  cout << endl;

  return 0;
}
