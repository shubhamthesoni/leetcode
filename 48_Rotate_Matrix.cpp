#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        for(int i=0;i<row; i++){
            for(int j=0; j<=i;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0;i<row;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
#if 0
    void display(vector<vector<int>>& V)
    {
      for(vector<int> T : V)
      {
        for(int X : T) cout << X << " ";
        cout << endl;
      }
      cout << "---------"<<endl;
    }

    void rotate(vector<vector<int>>& matrix, int row)
    {
      int len = matrix.size();
      for(int i = row; i < len-1-row; i++)
      {
        int temp = matrix[row][i];
        matrix[row][i] = matrix[len -1 -i][row];
        matrix[len -1 -i][row] = matrix[len -1 -row][len -1 -i];
        matrix[len -1 -row][len -1 -i] = matrix[i][len -1 -row];
        matrix[i][len -1 -row] = temp;
      }
      return;
    }

    void rotate(vector<vector<int>>& matrix) {
      int len = matrix.size();
      for(int i = 0; i < len/2 ; i++) rotate(matrix, i);   
      return;
    }
#endif
};


int main()
{
  vector<vector<int>> V = {{1,2,3},{4,5,6},{7,8,9}};
  //vector<vector<int>> V = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

  Solution().rotate(V);

  for(vector<int> T : V)
  {
    for(int X : T) cout << X << " ";
    cout << endl;
  }
 
  return 0;
}
