class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        int low = 0; 
        int high = n;
        for(int i = 0; i < m; i++)
        {
            while(low < high)
            {
                int mid = low + (high - low)/2;
                if(grid[i][mid] >= 0) { low = mid + 1; }
                else high = mid; 
            }

            //cout << "Low : "<<low<<" High : " << high << endl;
            count += (n - low);
            high = low;
            low = 0;

        }
        return count;
    }
};
