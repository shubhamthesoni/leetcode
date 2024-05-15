#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
      int lastStep = nums.size();
      int maxJump = nums[0] + 1;
      for(int i = 1; i < lastStep; i++)
      { 
        if(maxJump >= lastStep) return true;
        if(maxJump < ( nums[i] + i  + 1)) maxJump = (nums[i] + i + 1);
        if(maxJump == (i+1)) return false;
      }
      return false;        
    }
};


int main()
{
  vector<int> V1 = {2,3,1,1,4};
  vector<int> V2 = {3,2,1,0,4};

  cout << Solution().canJump(V1) << endl;
  cout << Solution().canJump(V2) << endl;

  return 0;
}
