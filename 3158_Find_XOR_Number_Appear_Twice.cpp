#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
       int ones = 0;
       int twos = 0;
       for(int X : nums)
       {
         ones ^= (X & ~twos);
         twos ^= (X & ~ones);
       } 
       return twos;
    }
};

int main()
{
  vector<int> V = {1,2,3};
  cout << Solution().duplicateNumbersXOR(V) << endl;
  return 0;
}
