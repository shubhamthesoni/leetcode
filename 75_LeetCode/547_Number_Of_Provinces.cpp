#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
       int count = 0;
       int len = isConnected.size();
       vector<int> DP(len, 0);

       function<void(int)> dfs = [&](int x) {
         DP[x] = 1;
         for(int i = 0; i < len; i++)
         {
           if(isConnected[x][i] == 0) continue;
           if(DP[i] == 1) continue;
           dfs(i);
         }
       };

       for(int i = 0; i < len; i++)
       {
           if(DP[i] == 1) continue;
           count++;
           dfs(i);
       }
       return count;
     }
};

int main()
{
  vector<vector<int>> V = {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
  cout << Solution().findCircleNum(V) << endl;
  return 0;
}
