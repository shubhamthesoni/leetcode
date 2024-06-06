#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
      int len = hand.size();
      if(len%groupSize != 0) return false;
      int group_count = len/groupSize;

      vector<pair<int, int>> G(group_count, {0,0});

      sort(hand.begin(), hand.end());

      for(int x: hand)
      {
        int i = 0;
        for(i = 0; i < group_count; i++)
        {
          if(G[i].first == 0) { G[i].first = x; G[i].second = 1; break; }
          if((G[i].first == (x-1))&&(G[i].second < groupSize)) { G[i].first = x; G[i].second += 1; break; }
        }
        if(i == group_count) return false;
      }

      return true;
    }
};

int main()
{
  vector<int> V = {1,2,3,6,2,3,4,7,8};
  cout << Solution().isNStraightHand(V, 3) << endl;
  return 0;
}
