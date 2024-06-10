#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        int result = 0;
        int cmax = 0;
        int nmax = 0;
        for(int i = 0; i < len-1; i++)
        {
            nmax = max(nmax, nums[i] + i);
            if(i == cmax)
            {
                result++;
                cmax = nmax;
            }
        }

        return result;
    }
};


int main()
{
  vector<int> V = {1,2,3};
  cout << Solution().jump(V) << endl;
  return 0;
}

