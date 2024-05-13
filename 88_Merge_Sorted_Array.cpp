#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int len = m+n;
       int i = len;
       while(m > 0 && n > 0)
       {
         if(nums1[m-1] > nums2[n-1]) { nums1[--i] = nums1[m-1]; m--; }
         else { nums1[--i] = nums2[n-1]; n--; }
       }

       while(n > 0) { nums1[--i] = nums2[n-1]; n--; }

    }
};

int main()
{
  vector<int> V1 = {1,2,3,0,0,0};
  vector<int> V2 = {2,5,6};
  Solution().merge(V1, 3, V2, 3);

  for_each(V1.begin(), V1.end(), [](int X){ cout << X <<" "; });
  cout << endl;

  return 0;
}
