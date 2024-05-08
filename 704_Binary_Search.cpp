#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
      int start = 0;
      int end = nums.size()-1;
      while(start <= end)
      {
        int mid = (start + end)/2;
        if(nums[mid] > target) { end = mid -1;}
        else if(nums[mid] < target) { start = mid+1;}
        else return mid;
      }
      return -1;       
    }
};

int main()
{
  vector<int> V = {-1,0,3,5,9,12};
  Solution solution;
  cout << solution.search(V, 9) <<endl;
  cout << solution.search(V, 2) <<endl;
  return 0;
}

