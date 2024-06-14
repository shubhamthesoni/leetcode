#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
      int len = costs.size();
      int lindex = min(candidates-1, len-1);      
      int rindex = max(lindex+1, len - candidates);

      priority_queue<int, vector<int>, greater<int>> L;
      priority_queue<int, vector<int>, greater<int>> R;
   
      for(int i = 0; i <= lindex; i++) { L.push(costs[i]);}
      for(int i = rindex; i < len; i++) { R.push(costs[i]); }

      long long cost = 0;
      while(k--)
      {
        int left = (L.empty() ? INT_MAX : L.top());
        int right = (R.empty() ? INT_MAX : R.top());
        //cout << "Loop : "<<left<<" : " <<right << " : "<<lindex<<" : "<<rindex <<endl;
        if(left <= right)
        {
          cost += left;
          L.pop(); 
          if(lindex < (rindex-1)) { lindex++; L.push(costs[lindex]);}
        }
        else
        {
          cost += right;
          R.pop();
          if(rindex > (lindex+1)) { rindex--; R.push(costs[rindex]);}
        }
      }
      return cost;
    }
};

int main()
{
  vector<int> V = {57,33,26,76,14,67,24,90,72,37,30};
  cout << Solution().totalCost(V, 11,2) << endl;
  return 0;
}
