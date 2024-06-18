class Solution {
public:
    int f(vector<pair<int,int>>& ans, int X)
{
    int mid;
    int low = 0;
    int high = ans.size();
    while (low < high) {
        mid = low + (high - low) / 2;
        if (X <= ans[mid].first) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
    if(low < ans.size() && ans[low].first < X) {
       low++;
    }
      if(low<0 || low>=ans.size())return -1;
        else
            return ans[low].second;
}
    vector<int> findRightInterval(vector<vector<int>>& nums) {
      vector<pair<int,int>> ans;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back({nums[i][0],i});
        }
        sort(begin(ans),end(ans));
        for(int i=0;i<nums.size();i++)
        {
            int y = f(ans,nums[i][1]);
            res.push_back(y);
        }
        return res;
    }
};
