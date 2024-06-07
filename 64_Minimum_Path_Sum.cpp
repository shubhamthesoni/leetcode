class Solution {
    int minPathSum(vector<vector<int>>& grid, vector<vector<int>>& DP, int row, int column)
    {
        int m = grid.size();
        int n = grid[0].size();
        if((row >= m) || (column >= n)) return 0;
        if(DP[row][column] != -1) return DP[row][column];

        int down = minPathSum(grid, DP, row+1, column);
        int right = minPathSum(grid, DP, row, column+1);

        DP[row][column] = grid[row][column] + min(right, down);
        return DP[row][column];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
    
        vector<vector<int>> DP(m, vector<int>(n, -1));

        DP[m-1][n-1] = grid[m-1][n-1];
        for(int i = n-2; i >=0; i--) DP[m-1][i] = DP[m-1][i+1] + grid[m-1][i];
        for(int i = m-2; i >=0; i--) DP[i][n-1] = DP[i+1][n-1] + grid[i][n-1];



        return minPathSum(grid, DP, 0, 0); 

        return DP[0][0];
    }
};
