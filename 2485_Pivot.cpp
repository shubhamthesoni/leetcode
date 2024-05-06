#include<iostream>

using namespace std;

class Solution {
public:
    int pivotInteger(int n) {

        int total_sum = (n * (n+1))/2;
        int loop_sum = 0;
        for(int i = 1; i <=n ; i++)
        {
            loop_sum = (i * (i+1))/2;
            if(loop_sum == (total_sum - loop_sum + i)) return i;
        }
        return -1;
        
    }
};


int main()
{

  Solution solution;
  cout << "Result " << solution.pivotInteger(8);
  cout << "Result " << solution.pivotInteger(1);
  cout << "Result " << solution.pivotInteger(4);
  return 0;
}
