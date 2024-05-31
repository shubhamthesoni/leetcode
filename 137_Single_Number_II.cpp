#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int ones = 0;
       int twos = 0;
       for(int X : nums)
       {
         ones ^= (X & ~twos);
         twos ^= (X & ~ones);
       } 
       return ones;
    }
};

int main()
{
  vector<int> V = {5,2,1,2,5,5,2};
  cout << Solution().singleNumber(V) << endl;
  return 0;
}
