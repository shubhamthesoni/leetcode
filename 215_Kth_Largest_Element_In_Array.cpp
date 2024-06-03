#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      priority_queue<int, vector<int>, greater<int>> Q(nums.begin(), nums.begin()+k);
      for(int i = k; i < nums.size(); i++)
      {
        if(nums[i] > Q.top()) { Q.pop(); Q.push(nums[i]); }
      }

      return Q.top();
    }
};


int main()
{
  vector<int> V = {3,2,3,1,2,4,5,5,6};
  cout << Solution().findKthLargest(V, 4) << endl;
  return 0;
}
