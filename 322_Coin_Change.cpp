#include <iostream>
#include <vector>
#include <climits>
#include <set>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       vector<int> DP(amount+1, amount+1); 
       DP[0] = 0;
       int max_coin = 0;

       for(int i = 1; i <= amount; i++)
       {
         for(int x: coins)
         {
           if((i-x) >= 0)
           {
             DP[i] = min(DP[i], 1 + DP[i-x]);
           }
         }
       }
       return (DP[amount] != (amount+1))? DP[amount]:-1;
    }
};

int main()
{
  vector<int> V = {2,10};
  for(int i = 0; i <= 25; i++)
  {
    cout << "Min Coins for "<<i<< " is : "<<Solution().coinChange(V, i)<<endl;
  }
  return 0;
}
