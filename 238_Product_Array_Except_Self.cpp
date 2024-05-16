#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int len = nums.size();
      vector<int> R(len, 0);
      int prev_prod = 1;
      for(int i = 0; i < nums.size(); i++)
      {
        R[i] = prev_prod;
        prev_prod *= nums[i];
      }

      prev_prod = 1;
      for(int i = len-1; i>=0; i--)
      {
        R[i] = prev_prod * R[i];
        prev_prod *= nums[i];
      }

      return R;       
    }
};

int main()
{
  vector<int> V = {-1,1,0,-3,3};
  V = Solution().productExceptSelf(V);
  for( int X : V)
  {
    cout << X << " ";
  }
  cout << endl;
  return 0;
}
