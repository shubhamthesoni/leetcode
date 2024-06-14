class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        //vector<vector<bool>> DP(m, vector<bool>(n, false));

        queue<pair<int, int>> Q;
        Q.push(make_pair(entrance[0], entrance[1]));
        maze[entrance[0]][entrance[1]] = '+';

        int count = 0;

        int direction[5] = {0, 1, 0, -1, 0};
        while(!Q.empty())
        {
            count++;
            int len = Q.size();
            while(len--)
            {
                pair<int, int> T = Q.front(); Q.pop();
                for(int i = 0; i < 4; i++)
                {
                    int xx = T.first + direction[i];
                    int yy = T.second + direction[i+1];
                    if((xx >= 0) && (xx < m) && (yy >=0) && (yy < n) && (maze[xx][yy] == '.'))
                    {
                        /* Check if it is at border */
                        if((xx == 0) || (xx == (m-1)) || (yy == 0) || (yy == (n-1))) return count;
                        Q.push(make_pair(xx, yy));
                        maze[xx][yy] = '+';
                    }
                }
            }
        }
        return -1;
    }
};
