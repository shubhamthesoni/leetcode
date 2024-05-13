#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int len = prices.size();
      int profit = 0;
#if 0
      vector<int > B(len, 0);
      vector<int > S(len, 0);

      B[0] = prices[0]; S[len-1] = prices[len-1];
      for (int i = 1; i < len; i++)
      {
        if(prices[i] < prices[i-1]) B[i] = prices[i];
        else B[i] = B[i-1];
      } 
      for (int i = len -2; i >= 0; i--)
      {
        if(prices[i] > prices[i+1]) S[i] = prices[i];
        else S[i] = B[i];
      }

      for(int i =0; i < len; i++) profit += (S[i] - B[i]);
#endif
      int start = prices[0];
      for(int i = 1; i < len; i++)
      {
        if(start < prices[i]) profit += (prices[i] - start);
        start = prices[i];
      }

      return profit;
    }
};


int main()
{
  vector<int> V1 = {7,1,5,3,6,4};
  vector<int> V2 = {1,2,3,4,5};
  vector<int> V3 = {7,6,4,3,1};

  cout << Solution().maxProfit(V1) <<endl;
  cout << Solution().maxProfit(V2) <<endl;
  cout << Solution().maxProfit(V3) <<endl;

  return 0;
}
