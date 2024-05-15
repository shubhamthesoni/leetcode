#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:

    int find_min(int m, int n, vector<vector<int>>& mat, vector<vector<int>>& result, int i, int j, vector<vector<int>>& V)
    {
      if((i < 0) || (i >= m) || (j <0) || (j >= n)) return INT_MAX;
      if(result[i][j] != -1) return result[i][j];
      if(mat[i][j] == 0) return 0;      

      int up = (i>0 && !V[i-1][j])? find_min(m,n,mat,result,i-1,j):INT_MAX;
      if(up == 0) { result[i][j] = 1; return result[i][j]; }
      int left = (j>0)? find_min(m,n,mat,result,i,j-1):INT_MAX;
      if(left == 0) { result[i][j] = 1; return result[i][j]; }

      int down = (i<(m-1))?find_min(m,n,mat,result,i+1,j):INT_MAX;
      if(down == 0) { result[i][j] = 1; return result[i][j]; }
      int right = (j<(n-1))? find_min(m,n,mat,result,i,j+1):INT_MAX;
      if(right == 0) { result[i][j] = 1; return result[i][j]; }

      result[i][j] = min(min(up,down), min(left, right)) + 1;
      return result[i][j];
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      int m = mat.size();
      int n = mat[0].size();
      vector<vector<int>> R(m, vector<int>(n, -1));
      vector<vector<bool>> V(m, vector<bool>(n, false));

      for(int i = 0; i < m; i++)
        for(int j = 0; j < n ; j++)
        {
          V[i][j] = true;
          R[i][j] = find_min(m, n , mat, R, i, j);
        }
      
      
     return R;       
    }
};


int main()
{
  //vector<vector<int>> V = {{0,0,0},{0,1,0},{1,1,1}};
  vector<vector<int>> V = {{0,1,0,1,1},{1,1,0,0,1},{0,0,0,1,0},{1,0,1,1,1},{1,0,0,0,1}};
  V = Solution().updateMatrix(V);
  cout << "{";
  for(int i = 0; i < V.size(); i++)
  {
    cout <<" {";
    for(int j = 0; j < V[0].size(); j++)
    {  cout << V[i][j]; if(j < V[0].size() -1) cout <<","; }
    cout<<"}"; if(i< V.size()-1) cout << ",";
  }
  cout<<" } " << endl;
  return 0;
}
