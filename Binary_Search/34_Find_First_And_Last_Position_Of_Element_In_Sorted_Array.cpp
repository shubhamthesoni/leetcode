class Solution {
    int searchRange(vector<int>& nums, int target, bool right) {
      int index = -1;
      int low = 0;
      int high = nums.size() -1;
      while(low <= high)
      {
        int mid = low + (high - low)/2;
        if(target < nums[mid]) { high = mid-1; }
        else if(target > nums[mid]) { low = mid+1; }
        else {
          index = mid;
          if(right) { low = mid+1; }
          else { high = mid-1; }
        }
      }
      return index;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int> R = {-1, -1};
      R[0] = searchRange(nums, target, false);
      R[1] = searchRange(nums, target, true);
      return R;
    }

};
