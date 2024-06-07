#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
      int len1 = s1.length();
      int len2 = s2.length();
      int len3 = s3.length();

      if((len1 == 0) && (len2 == 0) && (len3 == 0)) return true;
      if((len1+len2) != len3) return false;

      vector<vector<int>> DP(len1+1, vector<int>(len2+1, -1));

      auto dfs = [&](int x, int y, auto&& dfs) {
        if((x == len1) && (y == len2)) return true;
        if(DP[x][y] != -1) return (DP[x][y] == 1);

        DP[x][y] = 0;

        if((x < len1) && (s1[x] == s3[x+y]))
          DP[x][y] = dfs(x+1, y, dfs);

        if((y < len2) && (s2[y] == s3[x+y]))
          DP[x][y] |= dfs(x, y+1, dfs);

        return (DP[x][y] == 1);
      };

      return dfs(0, 0, dfs);      
    }
};

int main()
{
  cout << Solution().isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
  return 0;
}
