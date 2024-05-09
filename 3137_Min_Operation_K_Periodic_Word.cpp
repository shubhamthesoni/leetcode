#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
      int len = word.length();
      map<string, int> P;
      int count = 0, maxP = 0;
      for(int i = 0; i < len; i=i+k)
      {
        string T = word.substr(i,k);
        maxP = max(maxP, ++P[T]);
      }
      return (len/k) - maxP;        
    }
};


int main()
{
  Solution solution;
  cout << solution.minimumOperationsToMakeKPeriodic("leetcodeleet", 4) << endl;
  cout << solution.minimumOperationsToMakeKPeriodic("leetcoleet", 2) << endl;
  return 0;
}
