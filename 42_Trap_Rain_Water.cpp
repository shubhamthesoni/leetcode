#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
      int len = height.size();
      vector<int> H(len, 0);
      int maxH = 0;
      int result = 0;
      for(int i = 0; i < len; i++)
      {
        maxH = max(maxH, height[i]);
        H[i] = maxH;
        //cout << "First : H["<<i<<"] = "<<H[i]<<endl;
      }
      maxH = 0;        
      for(int i = len-1; i >= 0; i--)
      {
        maxH = max(maxH, height[i]);
        H[i] = min(maxH, H[i]);
        //cout << "Second : H["<<i<<"] = "<<H[i]<<endl;
        result += (height[i] < H[i]) ? (H[i] - height[i]) : 0;
      }

      return result;
    }
};


int main()
{
  vector <int> V1 = {0,1,0,2,1,0,1,3,2,1,2,1};
  vector <int> V2 = {4,2,0,3,2,5};

  cout << Solution().trap(V1) << endl; 
  cout << Solution().trap(V2) << endl; 

  return 0;
}
