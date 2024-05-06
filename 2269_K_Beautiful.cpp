#include<iostream>
#include<cmath>

using namespace std;

class Solution {
public:
    int divisorSubstrings(int orig_num, int k) {
        int b_num = 0;
        int result = 0;
        int k_pow = pow(10,k);
        int num = orig_num;
        
        b_num = num%k_pow; 
        if(b_num && !(num%b_num)) result++;
        printf("b_num : %d, result : %d, num : %d\n", b_num, result, num);

        num /= k_pow;

        while(num)
        {
          printf("Before b_num : %d, result : %d, num : %d\n", b_num, result, num);
          b_num = ((num%10)*(k_pow) + b_num)/10;
          if(b_num && !(orig_num%b_num)) result++;
          num /= 10;
          printf("After b_num : %d, result : %d, num : %d\n", b_num, result, num);
        }

        return result;
    }
};


int main()
{
  Solution solution;
  cout << "Result is "<< solution.divisorSubstrings(430043, 2);
  cout << "Result is "<< solution.divisorSubstrings(1000000000, 10);

  return 0;
}
