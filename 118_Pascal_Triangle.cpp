#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
  vector<vector<int>> generate(int numRows) 
  {
    vector<vector<int>> result(numRows);

    {
      vector<int> row(1, 1);
      result[0] = row;
    }

    for(int i = 1; i < numRows; i++)
    {
      vector<int> row(i+1, 1);
      for(int j = 1; j < (i); j++)
      {
        row[j] = result[i-1][j-1] + result[i-1][j];
      }
      result[i] = row;
    }
    
    return result;
  }
};



int main()
{
  Solution solution;
  solution.generate(5);
  return 0;
}
