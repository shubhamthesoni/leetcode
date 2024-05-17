#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
 
      int total_gas = 0;
      int total_cost = 0;
      int tank = 0;
      int index = 0;
      for(int i = 0; i < gas.size(); i++)
      {
        total_gas += gas[i];
        total_cost += cost[i];
        tank += (gas[i] - cost[i]);
        if(tank < 0) { tank = 0; index = i+1; }
      }
      return (total_gas >= total_cost) ? index:-1;
    }
};


int main()
{
  vector<int> G = { 1,2,3,4,5};
  vector<int> C = { 3,4,5,1,2};

  cout << Solution().canCompleteCircuit(G,C) << endl;
  return 0;
}
