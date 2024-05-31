#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
       int trailingZero = 0;
       int divisor = 5;
       while(divisor <= n)
       {
         trailingZero += (n/divisor);
         divisor *= 5;
       }
       return trailingZero;
    }
};


int main()
{
  cout << Solution().trailingZeroes(3) << endl;
  cout << Solution().trailingZeroes(5) << endl;
  cout << Solution().trailingZeroes(0) << endl;
  return 0;
}
