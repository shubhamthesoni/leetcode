#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
      int len = profits.size();
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> MinPQ;
      for(int i = 0; i < len; i++) MinPQ.push({capital[i], profits[i]});

      priority_queue<int> PQ;
      while((k > 0) && (!MinPQ.empty()))
      { 
        while((!MinPQ.empty())&&(MinPQ.top().first <= w))
        {
          PQ.push(MinPQ.top().second);
          MinPQ.pop();
        }
     
        if(PQ.empty()) break;
        w += PQ.top(); PQ.pop();
        k--;
        
      }

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
