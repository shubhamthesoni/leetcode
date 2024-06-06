#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
      int len = s.length();
      vector<vector<int>> DP(len, vector<int>(len, 0));
      array<int, 2> ans = {0, 0};
      for(int i = 0; i < len; i++) DP[i][i] = 1;
      for(int i = 0; i < len-1; i++) if(s[i] == s[i+1]) { DP[i][i+1] = 1; ans = {i, i+1}; }

      for(int diff = 2; diff < len; diff++)
      {
        for(int i = 0; i < len-diff; i++)
        {
          int j = i + diff;
          if((s[i]==s[j]) && (DP[i+1][j-1])) { DP[i][j] = 1; ans = {i, j}; }
        }
      }

      return  s.substr(ans[0], ans[1] - ans[0] + 1);
    }
};

int main()
{
  cout << Solution().longestPalindrome("babad") << endl;
  return 0;
}
