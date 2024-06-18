class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 0) return true;
        for(int i = 1; i <= sqrt(c); i++ )
        {
            {
                int rem = c - (i*i);
                int sq = sqrt(rem);
                //cout << rem << ":" << sq << endl;
                if((sq*sq) == rem) return true;
            }
        }
        return false;
    }
};
