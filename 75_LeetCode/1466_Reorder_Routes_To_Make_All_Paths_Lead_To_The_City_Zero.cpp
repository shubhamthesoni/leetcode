#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
    void display(vector<vector<bool>> & DP)
    {
      cout << "Display"<<endl;
      for(vector<bool> T : DP)
      {
        for(bool x : T ) cout << x << " ";
        cout << endl;
      }
      return;
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
      vector<set<int>> F(n);
      vector<set<int>> R(n);
      for(vector<int> T : connections)
      {
        F[T[0]].insert(T[1]);
        R[T[1]].insert(T[0]);
      }       

      queue<int> Q;
      Q.push(0);
      int count = 0;
      set<int> S;
      S.insert(0);

      while(!Q.empty())
      {
        int T = Q.front(); Q.pop();
        
        set<int> D = F[T];
        for(auto x : D) { if(S.find(x) != S.end()) continue; count++; F[T].erase(x); Q.push(x); S.insert(x); }
        D = R[T];
        for(auto x : D) { if(S.find(x) != S.end()) continue; F[T].erase(x); Q.push(x); S.insert(x); }
       
        cout << "Count "<< count <<endl;
      }
      return count;
    }
};

int main()
{
  vector<vector<int>> V = {{0,1},{1,3},{3,2},{4,0}, {4,5}};
  cout << Solution().minReorder(6, V) << endl;
  return 0;
}
