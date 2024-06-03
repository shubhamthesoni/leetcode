#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
       int len = nums.size();
       bool flag = true;
       int curr_max = nums[0];
       for(int i = 1; i < len; i++)
       {
         if(nums[i] <= curr_max) { if(!flag) return false; flag = false; }
         else curr_max = nums[i];
       } 
       return true;
    }
};


int main()
{
  Solution solution;
  vector<int> V = { 1,2, 10, 4, 5};
  cout << solution.canBeIncreasing(V);
  cout << endl;
  return 0;
}
