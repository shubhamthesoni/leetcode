class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> Q;
        int fresh = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2)
                {
                    Q.push(make_pair(i,j));
                }
            }
        }

        if(fresh == 0) return 0;

        int direction[5] = {0, 1, 0, -1, 0};
        int minutes = 0;
        while(!Q.empty())
        {
            minutes++;
            int len = Q.size();
            while(len--)
            {
                pair<int, int> T = Q.front(); Q.pop();
                for(int i = 0; i < 4; i++)
                {
                    int xx = T.first + direction[i];
                    int yy = T.second + direction[i+1];

                    if((xx >= 0) && (xx < m) && (yy >= 0) && (yy < n) && (grid[xx][yy] == 1))
                    {
                        grid[xx][yy] = 2;
                        fresh--;
                        if(fresh == 0) return minutes;
                        Q.push(make_pair(xx,yy));
                    }
                }
            }
        }

        return -1;
    }
};

        
