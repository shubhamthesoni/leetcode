class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int len = word.length();
        vector<vector<bool>> V(m, vector<bool>(n, false));

        function<bool(int, int, int)> dfs = [&](int x, int y, int index) {

            //cout << "X : "<<x<<" Y : "<<y<< "Index : "<<index<<endl;
            if(index >= len) return true;
            if(word[index] != board[x][y]) return false;

            if(index == (len-1)) return true;


            V[x][y] = true;
            int direction[5] = { 0, 1, 0, -1, 0};
            for(int i = 0; i < 4; i++)
            {
                int xx = x + direction[i];
                int yy = y + direction[i+1];
                //cout << "XX : "<<xx<<" YY : "<<yy<<endl;
                if((xx >= 0) && (xx < m) && (yy >=0) && (yy < n) && (V[xx][yy] == false))
                {
                    if(dfs(xx, yy, index+1) == true) return true;
                }
            }
            V[x][y] = false;
            return false;
        };

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(dfs(i, j, 0) == true) return true;
            }
        }
        return false;
    }
};
