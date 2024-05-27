#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int D[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    void gameOfLife(vector<vector<int>>& board) {
      vector<vector<int>> R = board;
      int m = board.size();
      int n = board[0].size();
      for(int i = 0; i < m; i++)
      {
        for(int j = 0; j < n ; j++)
        {
          int count = 0;
          for(int k = 0; k < 8; k++) 
          {
            int dx = i+D[k][0], dy = j+D[k][1];
            if((dx < 0) || (dx >= m) || (dy < 0) || (dy >= n)) continue;
            count += R[dx][dy];
          }

          /* Cond 1 */
          if(R[i][j] == 1)
          {
            if((count >= 2) && (count <=3)) board[i][j] = 1;
            else board[i][j] = 0;
          }
          else
          {
            if(count == 3) board[i][j] = 1;
          }
        }
      }   
    }
};


int main()
{
  vector<vector<int>> V = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
  Solution().gameOfLife(V);

  for(vector<int> T: V)
  {
    for(int X : T) cout << X << " ";
    cout << endl;
  }
  return 0;
}
