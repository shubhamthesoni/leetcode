class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> M;
        int len = grid.size();
        for(int i = 0; i < len; i++)
        {
            M[grid[i]]++;
        }

        int count = 0;
        for(int i = 0; i < len; i++)
        {
            vector<int> T;
            for(int j = 0; j < len; j++) T.push_back(grid[j][i]);
            count += M[T];
        }
        return count;
    }
};
