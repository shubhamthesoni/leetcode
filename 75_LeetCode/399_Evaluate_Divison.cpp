#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <set>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
      map<string, vector<pair<string, double>>> M;
      vector<double> R;
      int len = values.size();
      for(int i = 0; i < len; i++)
      {
        M[equations[i][0]].push_back({equations[i][1],values[i]});
        M[equations[i][1]].push_back({equations[i][0],1/values[i]});
      }

      set<string> S;

      function<double(string, string, set<string>)> evaluate = [&](string src, string dest, set<string> S) {
        if(M.find(src) == M.end()) return (double)-1.0;
        if(M.find(dest) == M.end()) return (double)-1.0;
        if(src == dest) return (double)1.0;

        S.insert(src);
        for(pair<string, double> T : M[src])
        {
          if(S.find(T.first) != S.end()) continue;
          double temp = evaluate(T.first, dest, S);
          if(temp != -1.0)
          {
            return (double) temp*T.second*1.0;
          }
        }
        return (double) -1.0;
      };


      for(int i = 0; i < queries.size(); i++)
      {
        R.push_back(evaluate(queries[i][0], queries[i][1], S));
      }
      return R;
    }
};


int main()
{
  vector<vector<string>> E = {{"a", "b"}, {"b", "c"}};
  vector<double> V = {2.0, 3.0};
  vector<vector<string>> Q = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

  V = Solution().calcEquation(E,V,Q);
  for(double d : V) cout << d << " ";
  cout << endl;
  return 0;
}
