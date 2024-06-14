#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
      vector<pair<int, int>> V;
      for(int i = 0; i < nums1.size(); i++) V.push_back(make_pair(nums2[i], nums1[i]));
      sort(V.begin(),V.end(),greater<>());
      
      priority_queue<int, vector<int>, greater<int>> PQ;

      long long maxS = LONG_MIN;
      long long sum = 0;

      for(int i = 0; i < nums1.size(); i++)
      {
        sum += V[i].second;
        PQ.push(V[i].second);
        if(PQ.size() < k) continue;
        if(PQ.size() == k)
        {
          maxS = max(maxS, sum*V[i].first);
          sum -= PQ.top();
          PQ.pop();
        }
      }
      return maxS;
    }
};

int main()
{
  vector<int> V1 = { 1,3,3,2 };
  vector<int> V2 = { 2,1,3,4 };

  cout << Solution().maxScore(V1, V2, 3) << endl;
  return 0;
}
