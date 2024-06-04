#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
      vector<vector<int>> R;
      //priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> PQ;
      priority_queue<tuple<int, int, int>> PQ;
      int N1 = 0, N2 = 0, L1 = nums1.size(), L2 = nums2.size();
      for(int i = 0; i < L1; i++)
      {
        if((PQ.size() == k) && (get<0>(PQ.top()) < (nums1[i]+nums2[0]))) break;
        for(int j = 0; j < L2; j++)
        {
          if((PQ.size() == k) && (get<0>(PQ.top()) < (nums1[i] + nums2[j]))) break;
          PQ.push(make_tuple(nums1[i]+nums2[j], nums1[i], nums2[j]));
          if(PQ.size() > k) PQ.pop();
        }
      } 

      while(k--) { tuple<int, int, int> T = PQ.top(); PQ.pop(); R.push_back({get<1>(T), get<2>(T)}); }

      return R;
      
    }
};

int main()
{
  vector<int> V1 = {1, 7, 11};
  vector<int> V2 = {2, 4, 6 };
  vector<vector<int>> V = Solution().kSmallestPairs(V1, V2, 3);
  for(vector<int> T : V) cout <<T[0] << " " << T[1] << endl;
  return 0;
}
