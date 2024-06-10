#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      int len = flowerbed.size();
      int count = 0;
      for(int i = 0; i < len; i++)
      {
        if(flowerbed[i] == 1) continue;
        if((i > 0) && (flowerbed[i-1] == 1)) continue;
        if((i < (len-1)) && (flowerbed[i+1] == 1)) continue;
        flowerbed[i] = 1; count++;
        if(count >= n) return true;
      }        
      return false;
    }
};

int main()
{
  vector<int> V = {1,0,0,0,1};
  cout << Solution().canPlaceFlowers(V, 1) <<endl;
  cout << Solution().canPlaceFlowers(V, 2) <<endl;
  return 0;
}
