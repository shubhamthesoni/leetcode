#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
    int minimumTotal(vector<vector<int>>& triangle, vector<vector<int>>& DP, int row, int column) {
      int height = triangle.size();
      if(row >= height) return 0;

      if(DP[row][column] != INT_MAX) return DP[row][column];
       
      int L = minimumTotal(triangle, DP, row+1, column);
      int R = minimumTotal(triangle, DP, row+1, column+1);
      DP[row][column] = triangle[row][column] + min(L, R);
      return DP[row][column];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
      int height = triangle.size();
      vector<vector<int>> DP(height, vector<int>(height, INT_MAX));

      return minimumTotal(triangle, DP, 0, 0);
    }
};


int main()
{
  vector<vector<int>> V = {{2}, {3,4}, {6,5,7}, {4,1,8,3}};
  cout << Solution().minimumTotal(V) << endl;
  return 0;
}
