#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
      int len = difficulty.size();
      int index = 0;
      vector<pair<int, int>> DP;
      for(int i = 0; i < difficulty.size(); i++) DP.push_back({difficulty[i], profit[i]});
      sort(DP.begin(), DP.end());

      sort(worker.begin(), worker.end());

      int totalP = 0;
      priority_queue<int> Q;
      for(int i = 0; i < worker.size(); i++)
      {
        while((index < len) && (worker[i] >= DP[index].first)) {  Q.push(DP[index].second); index++; }
        if(!Q.empty()) { totalP += Q.top(); }
      } 
      return totalP;
    }
};

int main()
{
  vector<int> D = {85, 47, 57};
  vector<int> P = {24, 66, 99};
  vector<int> W = {40, 25, 25};
  cout << Solution().maxProfitAssignment(D, P, W)<<endl;
  return 0;
}
