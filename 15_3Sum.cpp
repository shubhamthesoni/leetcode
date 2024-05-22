#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> R;
       sort(nums.begin(), nums.end());
       int i, j, k, len=nums.size();
       for(i = 0; i < len; i++)
       {
         if((i > 0) && (nums[i] == nums[i-1])) continue;
         j = i+1;
         k = len -1;
         while(j < k)
         {
           int total = nums[i] + nums[j] + nums[k];
           if(total > 0) { k--; }
           else if(total < 0) { j++; } 
           else 
           {
             R.push_back({nums[i], nums[j], nums[k]});
             j++;
             while((j < k) && (nums[j] == nums[j-1])) j++;
           }     
         }
       }
       return R;
    }
};


int main()
{
  vector<int> V = {-1,0,1,2,-1,-4};
  vector<vector<int>> R = Solution().threeSum(V);
  for(auto T : R )
  {
    for(auto N : T)
      cout << N << " ";
    cout << endl;
  }
  return 0;
}
