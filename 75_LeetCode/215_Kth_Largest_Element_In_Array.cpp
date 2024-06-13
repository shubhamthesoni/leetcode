class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      priority_queue<int, vector<int> , greater<int>> Q(nums.begin(), nums.begin()+k);
      for(int x = k; x < nums.size(); x++)
      {
         if(Q.top() < nums[x]) { Q.pop(); Q.push(nums[x]);}
      }

      return Q.top();
        
    }
};
