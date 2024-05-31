#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
      int m = board.size();
      int n = board[0].size();
      vector<pair<int, int>> R(m, {0,0});
      vector<pair<int, int>> C(n, {0,0});

      for(int i = 0; i < m; i++)
      {
        int first = 0;
        int found = 0;
        int j = 0;
        for(j = 0;j < n; j++) { if(board[i][j] == 'X') break; }
        first = j;
        for(j = n-1; j > first; j--) { if(board[i][j] == 'X') break; }
        R[i] = {first, j};
      }

      for(int i = 0; i < n; i++)
      {
        int first = 0;
        int found = 0;
        int j = 0;
        for(j = 0;j < m; j++) { if(board[j][i] == 'X') break; }
        first = j;
        for(j = m-1; j > first; j--) { if(board[j][i] == 'X') break; }
        C[i] = {first, j};
      }

      for(int i = 0; i < m; i++)
      {
        for(int j = 0; j < n; j++)
        {
          if(board[i][j] == 'X') continue;
          if((R[i].first < j) && (j < R[i].second) && (C[j].first < i) && (i < C[j].second)) board[i][j] = 'X';  
        }
      }

      return;
    }
};


int main()
{
  //vector<vector<char>> B = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}} ;
  vector<vector<char>> B = {{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}} ;
  for(vector<char> V : B)
  { 
    cout << "[ ";
    for(char X : V ) cout << X << " ";
    cout << "] "<<endl;
  }
    cout <<endl;
  Solution().solve(B);
  for(vector<char> V : B)
  { 
    cout << "[ ";
    for(char X : V ) cout << X << " ";
    cout << "] "<<endl;
  }
  return 0;
}
