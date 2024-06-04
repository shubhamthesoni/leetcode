#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#if 0
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, h = nums.size() -1;
        while(l < h)
        {
            int m = l + (h -l)/2;
            if(nums[m] < nums[m+1]) l = m +1;
            else h = m;
        }
        return l;
    }
};
#endif

class Solution {

     int search(vector<int> & nums, int low, int high)
     {
       if(low > high) return -1;
       int mid = low + (high-low)/2;
       printf("%d %d %d %d\n", mid, nums[mid-1], nums[mid], nums[mid+1]);
       if((nums[mid] > nums[mid-1]) && (nums[mid]> nums[mid+1])) return mid;
       
       int index = search(nums, mid+1, high );
       if(index == -1) index = search(nums, low, mid-1);
       return index;
     }

public:
    int findPeakElement(vector<int>& nums) {
      nums.insert(nums.begin(), INT_MIN);        
      nums.push_back(INT_MIN);
      return search(nums, 1, nums.size()-2) - 1;        
    }
};


int main()
{
  vector<int> V1 = {0};
  vector<int> V2 = {1, 2, 1, 3, 5, 6, 4};
  cout << Solution().findPeakElement(V1) << endl;
  cout << Solution().findPeakElement(V2) << endl;
  return 0;
}
