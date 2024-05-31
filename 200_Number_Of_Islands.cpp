#include <iostream>
#include <vector>

using namespace std;


class Solution {
    void visit(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& V) {
      int m = grid.size();
      int n = grid[0].size();

      if((i < 0) || (i >= m) || (j < 0) || ( j >= n) || (V[i][j] == true) || (grid[i][j] == '0') ) return;      
      
      V[i][j] = true;
      int direction[] = { 0, -1, 0, 1, 0 };
      
      for(int k = 0; k < 4; k++)
        visit(grid, i + direction[k], j + direction[k+1], V);      

      return;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      vector<vector<bool>> V(m, vector<bool>(n, false));
      int count = 0;
      for(int i = 0; i < m; i++)
      {
        for(int j = 0; j < n; j++)
        {
          if(V[i][j]) continue;
          if(grid[i][j] == '0') { V[i][j] = true; continue; }
          count++;
          visit(grid, i, j, V);
        }
      }
      return count;        
    }
};


int main()
{
  vector<vector<char>> G ={{'1','1','0','0','0'},
                           {'1','1','0','0','0'},
                           {'0','0','1','0','0'},
                           {'0','0','0','1','1'}};
  cout << Solution().numIslands(G) << endl;
  return 0;
}
