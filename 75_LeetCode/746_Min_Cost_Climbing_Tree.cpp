#include <iostream>
#include <vector>
#include <climits>

using namespace std;


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      int totalSteps = cost.size();
      int minCost[totalSteps+1] = {INT_MAX};
      //for(int i = 0; i < totalSteps; i++) cout << cost[i] << endl;
      minCost[0] = 0;
      minCost[1] = cost[0];
      for(int i = 2; i <= totalSteps; i++)
      {
        minCost[i] = cost[i-1] + min(minCost[i-1], minCost[i-2]);
      }

      return min(minCost[totalSteps], minCost[totalSteps-1]); 
    }
};


int main()
{
  Solution solution;
  vector<int> C = {1,100,1,1,1,100,1,1,100,1};
  cout << solution.minCostClimbingStairs(C) << endl;
  return 0;
}
