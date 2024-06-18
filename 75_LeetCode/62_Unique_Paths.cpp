class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> DP(m, vector<int>(n, -1));
        //DP[0][0] = 1;
        function<int(int, int)> dfs = [&](int x, int y) {

            if((x==(m-1))&&(y==(n-1))) return 1;
            int count = 0;

            if(DP[x][y]!= -1) return DP[x][y];

            if(x<(m-1))
                count += dfs(x+1, y);
            if(y<(n-1))
                count += dfs(x, y+1);
            DP[x][y] = count;
            return DP[x][y];
        };

        dfs(0, 0);
        return (DP[0][0] == -1) ? 1 : DP[0][0];
    }
};
