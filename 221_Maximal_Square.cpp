class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> DP(m, vector<int>(n, 0));
        
        int maxLen = 0;
        for(int i = m-1; i >= 0; i--)
        {
            for(int j = n-1; j >= 0; j--)
            {
                if(matrix[i][j] == '0') { continue; }
                int down = (i <= m-2) ? DP[i+1][j] : 0;
                int right = (j <= n-2) ? DP[i][j+1] : 0;
                int cross = ((i <= m-2) && (j <= n-2)) ? DP[i+1][j+1] : 0;
                DP[i][j] = 1 + min(down, min(right, cross));
                maxLen = max(maxLen, DP[i][j]);
            }
        }
        return maxLen*maxLen;
    }
};
