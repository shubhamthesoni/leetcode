#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
      vector<int> R;
      int X = 0;
      int leftBit = 0;
      int A =0, B= 0;

      for(int x : nums) X ^= x;

      while((X & 1) != 1) { leftBit++; X >>= 1; }

      for(int x : nums)
      {
        if(((x>>leftBit)&1) == 1) A ^= x; 
        else B ^= x;
      }

      return {A,B}; 
    }
};


int main()
{
  vector<int> V = {1,2,1,3,2,5};
  V = Solution().singleNumber(V);
  for(int X : V) cout << X << " ";
  cout << endl;
  return 0;
}
