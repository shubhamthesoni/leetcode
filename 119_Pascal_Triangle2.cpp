#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
  vector<vector<int>> generate(int numRows) 
  {
    vector<int> prev;
    for(int i = 0; i < numRows; i++)
    {
      vector<int> row(i+1, 1);
      for(int j = 1; j < (i); j++)
      {
        row[j] = prev[j-1] + prev[j];
      }
      prev = row;
    }
    
    return prev;
  }
};



int main()
{
  Solution solution;
  solution.generate(5);
  return 0;
}
