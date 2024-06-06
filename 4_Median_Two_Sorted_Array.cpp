#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int len1 = nums1.size();
       int len2 = nums2.size();
       int totallen = len1 + len2;
       
       if((len1 == 0) && (len2 == 0)) return 0;
       if(len1 == 0) { if(len2%2 == 0) return (nums2[len2/2] + nums2[len2/2 -1])/2.0;  else return nums2[len2/2]; }
       if(len2 == 0) { if(len1%2 == 0) return (nums1[len1/2] + nums1[len1/2 -1])/2.0;  else return nums1[len1/2]; }
       
       if(nums2[len2-1] < nums1[0]) { if(len1 == len2) return (num2[len2-1] + num1[0])/2.0; else if(len1 }
       if(nums1[len1-1] < nums2[0]) {}
       
       
    }
};


int main()
{
  vector<int> V1 = {1,2};
  vector<int> V2 = {3,4};
  cout << Solution().findMedianSortedArrays(V1, V2) << endl;
  return 0;
}
