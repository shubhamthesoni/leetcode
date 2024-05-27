#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      int len = strs.size();
      vector<vector<string>> result;
      map<string, vector<string>> M;
      for(int i = 0; i < len; i++)
      {
        string S = strs[i];
        sort(S.begin(), S.end());
        M[S].push_back(strs[i]);
      }        
      map<string, vector<string>>:: iterator itr;
      for(itr = M.begin(); itr != M.end(); itr++)
      {
        esult.push_back(itr->second);
      }
      return result;
    }
};

int main()
{
  vector<string> V = {"eat","tea","tan","ate","nat","bat"};
  vector<vector<string>> S = Solution().groupAnagrams(V);
  for(vector<string> R : S)
  {
    for(string T : R) cout << T << " ";
    cout << endl;
  }

  return 0;
}
