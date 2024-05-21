#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
      long long result = 0;
      vector<vector<int>> F(10, vector<int>(10,0));
      int j = 0;
      while(nums[0] > 0) 
      {
        for(int i = 0; i < nums.size(); i++)
        {
          F[j][nums[i]%10]++;
          nums[i] /= 10;
        }
        j++;
      }

      while(j--)
      {
        for(int X : F[j]) { /* cout << "F["<<j<<"][X] = "<<X << endl; */ result += (X * (nums.size() - X)); }
      }
      return result/2;
    }
};


int main()
{
  vector<int> V = {324, 436, 298, 192, 290};
  cout << Solution().sumDigitDifferences(V) << endl;
  return 0;
}
