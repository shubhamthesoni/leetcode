#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
       int len = prices.size();
       vector<vector<vector<int>>> V(len+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

       for(int i = len-1; i >= 0; i--)
       {
         for(int j = 0; j <=1 ; j++)
         {
           for(int l = 1; l <= k; l++)
           {
             if(j == 0) V[i][j][l] = max(V[i+1][0][l], V[i+1][1][l] - prices[i]);
             else V[i][j][l] = max(V[i+1][1][l], V[i+1][0][l-1] + prices[i]);
           }
         }
       }
       return V[0][0][k];
    }
};


int main()
{
  vector<int> V = {3,2,6,5,0,3};
  cout << Solution().maxProfit(2, V) << endl;
  return 0;
}
