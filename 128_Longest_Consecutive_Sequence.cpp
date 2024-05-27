#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      int len = nums.size();
      set<int> S;
      for(int X : nums) S.insert(X);
      int longest = 0;

      for(int X : nums)
      {
        if(S.find(X-1) == S.end())
        {
          int count = 1;
          X = X+1;
          while(S.find(X) != S.end()) { X++; count++;}
          longest = max(longest, count);
        }
      }

#if 0
      sort(nums.begin(), nums.end());
      int longest = 0;
      int start = 0;
      int negative = 0;
      for(int i = 1; i < len; i++)
      {
        if(nums[i] == nums[i-1]) { negative++; continue; }
        if(nums[i] != (nums[i-1] + 1))
        {
          longest = max(longest, (i-start - negative));
          start = i;
          negative = 0;
        }
      }
      longest = max(longest, (len-start - negative));
#endif
      return longest; 
    }
};


int main()
{
  vector<int> V = {0,3,7,2,5,8,4,6,0,1};
  //vector<int> T = {100,4,200,1,3,2};
  vector<int> T = {1,2,0,1};

  cout << Solution().longestConsecutive(V) << endl; 
  cout << Solution().longestConsecutive(T) << endl; 
 
  return 0;
}
