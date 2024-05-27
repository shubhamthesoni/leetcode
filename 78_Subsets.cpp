#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> R;
    R.push_back({});
    int len = nums.size();
    
    for(int X : nums)
    {
      int curr_len = R.size();
      for(int i  = 0; i < curr_len; i++)
      {
        vector<int> V = R[i];
        V.push_back(X);
        R.push_back(V);
      }
    }

    return R;
  }
};

#if 0
class Solution {

    vector<vector<int>> R;
    void generate(vector<int> V, vector<int>& nums, int index, int len)
    {
      for(int i = index; i < len; i++)
      {
        vector<int> D = V;
        D.push_back(nums[i]);
        R.push_back(D);
        generate(D, nums, i+1, len);
      }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
      int len = nums.size();

      for(int i = 0; i < len ; i++)
      {
        vector<int> V;
        V.push_back(nums[i]);
        R.push_back(V);
        generate(V, nums, i+1, len);
      }

      return R;
    }
};
#endif


int main()
{
  vector<int> V = {1,2,3,4};
  vector<vector<int>> R = Solution().subsets(V);
  for(vector<int> D: R)
  {
    for(int X: D) cout << X << " ";
    cout << endl;
  }
  return 0;
}
