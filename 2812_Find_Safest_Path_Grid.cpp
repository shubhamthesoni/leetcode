#include<iostream>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

int direction[] = {0,1,0,-1,0};

class Solution {
public:

    bool isValid(int len, int x, int y)
    {
      return ((x>=0)&&(y>=0)&&(x<len)&&(y<len));
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
      int len = grid.size();
      if((grid[0][0]==1)||(grid[len-1][len-1]==1)) return 0;
      
      queue<pair<int,int>> Q;   
      int dx,dy;

      for(int i = 0; i < len; i++)
      {
        for(int j = 0; j < len; j++)
        {
          if(grid[i][j] == 1) { Q.push({i,j}); grid[i][j]=0;}
          else { grid[i][j]=-1;}
        }
      }

      while(!Q.empty())
      {
        pair<int,int> curr = Q.front();
        Q.pop();
        int curr_val = grid[curr.first][curr.second];
        for(int i = 0; i < 4; i++)
        {
          dx = curr.first + direction[i];
          dy = curr.second + direction[i+1];
          if(isValid(len,dx,dy) && (grid[dx][dy] == -1)) { grid[dx][dy] = curr_val+1; Q.push({dx,dy}); }
        }
      }

      for(int i = 0; i < len; i++)
      {
        cout <<"{ ";
        for(int j = 0; j < len; j++)
        {
          cout << grid[i][j]<<",";
        }
        cout <<"}"<<endl;
      }

      /* Time to find out the maxSafe */
      int maxSafe = 0;
      

      
      return 0;
    }
};


int main()
{
  vector<vector<int>> V = {{0,0,0,1}, {0,0,0,0}, {0,0,0,0}, {1,0,0,0}};
  cout << Solution().maximumSafenessFactor(V)<<endl;
  return 0;
}
