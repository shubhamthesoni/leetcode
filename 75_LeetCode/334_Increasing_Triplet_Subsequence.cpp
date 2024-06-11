class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int first = INT_MAX;
        int second = INT_MAX;
        for(int x : nums)
        {
            if(x <= first) first = x;
            else if(x <= second) second = x;
            else return true;
        }
        return false;
    }
};
