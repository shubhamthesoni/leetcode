class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        vector<bool> DP(len+1, false);
        set<string> S;

        DP[0] = true;
        int max_len = 0;

        for(string W : wordDict)
        {
            S.insert(W);
            max_len = max(max_len, static_cast<int>(W.length()));
        }

        for(int i = 1; i <= len; i++)
        {
            for(int j = i-1; j >= max(0, (i - max_len -1)); j--)
            {
                if(DP[j] && (S.find(s.substr(j, i-j)) != S.end()))
                {
                    DP[i] = true; 
                    break;
                }
            }
        }

        return DP[len];
    }
};
