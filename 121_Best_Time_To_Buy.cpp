#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<int> minP(len, 0);
        vector<int> maxP(len, 0);
        int maxProfit = 0;
        minP[0] = prices[0];
        maxP[len-1] = prices[len-1];
        for(int i = 0; i < len; i++)    
        {
            if(i!=0)
            {
                minP[i] = min(minP[i-1], prices[i]);
                maxP[len - i - 1] = max(maxP[len-i], prices[len - i -1]);
            }
        }

        for(int i = 0; i < len; i++)
        {
	    cout << "Index: "+ to_string(i) + " Min: " + to_string(minP[i]) + " Max: " + to_string(maxP[i]) << endl;
            maxProfit = max(maxProfit, (maxP[i]-minP[i]));
        }
        return maxProfit;
    }
};


int main()
{
  Solution solution;
  vector<int> P = {7,6,4,3,1};
  cout << solution.maxProfit(P) << endl;
  return 0;
}
