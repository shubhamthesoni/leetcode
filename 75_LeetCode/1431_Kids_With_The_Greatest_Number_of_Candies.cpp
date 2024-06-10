class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int len = candies.size();
        vector<bool> R(len, false); 
        int maxCandy = 0;
        for(int x: candies) maxCandy = max(maxCandy, x);

        for(int i = 0; i < len; i++)
        {
            if((candies[i] + extraCandies) >= maxCandy) R[i] = true;
        }
        return R;
    }
};
