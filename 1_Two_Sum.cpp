#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      map<int, int> S;
      int len = nums.size();
      for(int i = 0; i < len; i++)
      {
        if(S.find(target - nums[i]) != S.end()) { return {S[target - nums[i]], i}; }
        S.insert({nums[i], i});
      }
      return {-1, -1};
    }
};


int main()
{
  vector<int> V = { 3, 2, 4};
  Solution solution;
  vector<int> R =  solution.twoSum(V, 6);
  cout << R[0] <<endl;
  cout << R[1] <<endl;
  return 0;
}
