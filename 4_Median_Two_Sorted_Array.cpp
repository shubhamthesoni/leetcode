#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        if(len1 > len2) return findMedianSortedArrays(nums2, nums1);

        int low = 0;
        int high = len1;
        int total = len1 + len2;
        int mid = (len1 + len2 + 1)/2;

        int count = 10;
        while(low <= high)
        {
            int mid1 = low + (high-low)/2;
            int mid2 = mid - mid1;

            printf("%d %d %d %d\n", low, mid1, high, mid2);
            int L1 = (mid1 -1 >=0) ? nums1[mid1-1] : INT_MIN;
            int L2 = (mid2 -1 >=0) ? nums2[mid2-1] : INT_MIN;
            int R1 = (mid1 < len1) ? nums1[mid1]   : INT_MAX;
            int R2 = (mid2 < len2) ? nums2[mid2]   : INT_MAX;

            //printf("L1: %d R1: %d L2: %d R2: %d\n", L1, R1, L2, R2);

            if((L1 <= R2) && (L2 <= R1))
            {
                if(total%2 == 0) return ((max(L1, L2) + min(R1, R2))/2.0);
                else return max(L1, L2);
            } 
            else if(L1 > R2)
            {
                high = mid1 - 1;
            }
            else
            {
                low = mid1 + 1;
            }
        }
        return -1;
    }
};

int main()
{
  vector<int> V1 = {1,2};
  vector<int> V2 = {3,4};
  cout << Solution().findMedianSortedArrays(V1, V2) << endl;
  return 0;
}
