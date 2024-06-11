#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
      int len = nums.size();
      int count = 0;
      int start = 0;
      int end = len-1;
      sort(nums.begin(), nums.end());
      while(start < end)
      {
        int sum = nums[start] + nums[end];
        if(sum == k) { start++; end--; count++; }
        else if(sum > k) { end--; }
        else { start++; }
      }
      return count;
    }
};
