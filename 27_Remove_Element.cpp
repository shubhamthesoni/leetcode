#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      int K = 0;
      int len = nums.size() - 1;
      while( K < len) 
      {
        while(nums[K] != val) K++;
        while(nums[len] == val) len--;
        nums[K] = nums[len];
        nums[len] = val;
        K++; len--;
      }
      return K+1;       
    }
};

int main()
{
  vector <int> V = {0,1,2,2,3,0,4,2};
  cout << Solution().removeElement(V, 2) <<endl;
  for_each(V.begin(), V.end(), [](int X) { cout << X << " "; });
  cout << endl;
  return 0;
}
