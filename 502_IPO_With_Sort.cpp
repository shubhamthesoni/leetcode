#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int pc_sort(pair<int, int> A, pair<int, int> B)
{
  if(A.first == B.first) return (A.second < B.second);
  return A.first < B.first;
}

class Solution {
public:

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
      vector<pair<int, int>> PC;
      int index = 0;
      int len = profits.size();

      for(int i = 0; i < profits.size(); i++)
        PC.push_back({capital[i], profits[i]});
      sort(PC.begin(), PC.end(), pc_sort);

      //for(pair<int, int> x: PC) cout << x.first << " "<< x.second <<endl;

      priority_queue<int> PQ;      
      
      while((k > 0) && (index < len))
      {
        while((index < len) && (PC[index].first <= w)) { PQ.push(PC[index++].second); }
        
        if(PQ.empty()) break;

        k--;
        w += PQ.top();
        PQ.pop();
      }

      while((k > 0) && (!PQ.empty())) { w += PQ.top(); PQ.pop(); k--; }

      return w;
    }
};


int main()
{
  vector<int> P = {1,2,3};
  vector<int> C = {0,1,2};
  cout << Solution().findMaximizedCapital(3,0,P,C)<<endl;
  return 0;
}
