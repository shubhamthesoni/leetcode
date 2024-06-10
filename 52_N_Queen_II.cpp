class Solution {
    void display(vector<vector<int>> & V)
    {
       cout << "Display Start"<< endl;
       for(vector<int> T : V)
       {
         for(int x : T) cout << x << " ";
         cout << endl;
       }
       cout << "Display End"<< endl;
    }

public:
    int totalNQueens(int n) {
      vector<vector<int>> V(n, vector<int>(n, 0));
      int count = 0;

      auto mark_visited = [&](int x, int y, vector<vector<int>>& V)
      {
        V[x][y] = 2;
        int j = 1;
        for(int i = x+1; i < n; i++)
        {
          V[i][y] = 1;
          if((y+j)<n) V[i][y+j] = 1;
          if((y-j)>=0) V[i][y-j] = 1;
          j++;
        }
      };

      function<int(int, vector<vector<int>>)> dfs = [&](int x, vector<vector<int>> V)
      {
        if(x >= n) 
        { 
          //display(V); 
          return 1; 
        }
        int count = 0;
        for(int i = 0; i < n; i++)
        {
          if(V[x][i] == 1) continue;
          vector<vector<int>> T = V;
          mark_visited(x, i, T);
          //display(T) ;
          count += dfs(x+1, T);
        }
        return count;
      };

      count = dfs(0, V);
      return count;
    }

};
