#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

class Solution {
    pair<int, int> convert(int loc, int size)
    {
      int i = (loc-1)/size;
      int j = 0;
      if(i%2 == 0) { j = (loc-1)%size; }
      else { j = (size - (loc-1)%size - 1); }
      i = size - i - 1;
      cout << "Converted "<<loc<<" To ["<<i<<"]["<<j<<"]"<<endl;
      return {i, j};
    }

    

public:
    int snakesAndLadders(vector<vector<int>>& board) {
      int N = board.size();
      set<int> S;

      //for(int i = 1; i < N*N; i++) convert(i, N); 
      //return 0;

      queue<int> Q;
      Q.push(1);
      S.insert(1);

      int steps = 0;
      while(!Q.empty())
      {
        steps++;
        int len = Q.size();
        cout << "Steps "<<steps<<" Q Size "<<len<<endl;
        while(len--)
        {
          int loc = Q.front(); Q.pop();
          for(int i = 1; i <= 6; i++)
          {
            int next_pos = loc + i;
            cout << "Checking for "<<next_pos<<endl;
            if(S.find(next_pos) != S.end()) continue;

            S.insert(next_pos);
            pair<int, int> P = convert(next_pos, N);
            if(board[P.first][P.second] != -1) next_pos = board[P.first][P.second];

            if(next_pos >= (N*N)) return steps;

            //S.insert(next_pos);
            Q.push(next_pos);
            cout << "Inserting "<<next_pos<<endl;
          }
        }
      }
      return -1;
    }
};


int main()
{
  //vector<vector<int>> B = {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
  vector<vector<int>> B = {{-1,-1,-1,46,47,-1,-1,-1},{51,-1,-1,63,-1,31,21,-1},{-1,-1,26,-1,-1,38,-1,-1},{-1,-1,11,-1,14,23,56,57},{11,-1,-1,-1,49,36,-1,48},{-1,-1,-1,33,56,-1,57,21},{-1,-1,-1,-1,-1,-1,2,-1},{-1,-1,-1,8,3,-1,6,56}};

  cout << Solution().snakesAndLadders(B) << endl;
  return 0;
}
