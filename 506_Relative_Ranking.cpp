#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
      int len = score.size();
      vector<string> S(len);
      priority_queue<pair<int, int>> PQ;

      for(int i = 0; i < len; i++) PQ.push({score[i], i});
      
      int count = 0;
      while(!PQ.empty())
      {
        pair<int, int> P = PQ.top();
        PQ.pop();
        if(count == 0) S[P.second] = "Gold Medal";
        else if(count == 1) S[P.second] = "Silver Medal";
        else if(count == 2) S[P.second] = "Bronze Medal";
        else S[P.second] = to_string(count +1);
        count++;
      }

      return S;
    }
};


int main()
{
  vector<int> I = {10,3,8,2,9,4};
  Solution solution;
  vector<string> S = solution.findRelativeRanks(I);
  
  vector<string>::iterator itr;
  for(itr = S.begin(); itr != S.end(); itr++)
  {
    cout << *itr <<" ";
  }

  cout << endl;
  return 0;
}  
