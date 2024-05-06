#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int dp[1001] = {-1};

    bool definiteWin(int n, bool aliceTurn)
    {
      if(dp[n] != -1) return dp[n];
      dp[n] = 0;
      for(int i = 1; i < n; i++)
      {
        if(n%i!=0) continue;
        if(aliceTurn)
        dp[n] = dp[n] || !definiteWin(n-i, !aliceTurn);
        else
        dp[n] = dp[n] && definiteWin(n-i, !aliceTurn);
      }
      return (aliceTurn) ? dp[n]: !dp[n]; 
    }

    bool divisorGame(int n) {
      dp[0] = 0;
      dp[1] = 0;
      dp[2] = 1;
      return definiteWin(n, true);
    }
};


int main()
{
  Solution solution;
  int N;
  cin >> N;
  cout << solution.divisorGame(N) << endl;
  return 0;
}
