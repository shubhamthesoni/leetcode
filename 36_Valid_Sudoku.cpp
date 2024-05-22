#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidRow(vector<vector<char>>& board, int row) {
      vector<char> M(255, 0);
      for(int i = 0; i < 9; i++)
      {
        if((board[row][i] != '.') && (M[board[row][i]] != 0)) return false;
        M[board[row][i]] = 1;
      }
      return true;
    }

    bool isValidColumn(vector<vector<char>>& board, int column) {
      vector<char> M(255, 0);
      for(int i = 0; i < 9; i++)
      {
        if((board[i][column] != '.') && (M[board[i][column]] != 0)) return false;
        M[board[i][column]] = 1;
      }
      return true;
    }

    bool isValidBlock(vector<vector<char>>& board, int row, int column) {
      vector<char> M(255, 0);
      for(int i = 0; i < 3; i++)
      {
        for(int j = 0; j < 3; j++)
        {
          if((board[i+row][j+column] != '.') && (M[board[i+row][j+column]] != 0)) return false;
          M[board[i+row][j+column]] = 1;
        }
      }
      return true;
    }
 

    bool isValidSudoku(vector<vector<char>>& board) {
      /* check for each row */
      for(int i = 0; i < 9; i++) if(!isValidRow(board, i)) return false;
      /* check for each column */
      for(int i = 0; i < 9; i++) if(!isValidColumn(board, i)) return false;
      /* check for each block */
      for(int i = 0; i < 9; i=i+3)
        for(int j = 0; j < 9; j = j+3) if(!isValidBlock(board, i, j)) return false; 
      return true;
    }
};


int main()
{
  vector<vector<char>> V = {{'5','3','.','.','7','.','.','.','.'},
                            {'6','.','.','1','9','5','.','.','.'},
                            {'.','9','8','.','.','.','.','6','.'},
                            {'8','.','.','.','6','.','.','.','3'},
                            {'4','.','.','8','.','3','.','.','1'},
                            {'7','.','.','.','2','.','.','.','6'},
                            {'.','6','.','.','.','.','2','8','.'},
                            {'.','.','.','4','1','9','.','.','5'},
                            {'.','.','.','.','8','.','.','7','9'}};
  cout << Solution().isValidSudoku(V) << endl;
  return 0;
}
