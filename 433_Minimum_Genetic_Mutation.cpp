#include <iostream>
#include <vector>
#include <unordered_set>
#include <functional>
#include <queue>

using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
      int len = 8;
      unordered_set<string> S;
      unordered_set<string> V;
      for(string x : bank) S.insert(x);

      // base case
      if(S.find(endGene) == S.end()) return -1;
      if(startGene == endGene) return 0;
      char M[4] = {'A','C','G','T'};

      function<int(string)> bfs = [&](string startGene) {

        int count = 0;   
        queue<string> Q;
        Q.push(startGene);
      
        while(!Q.empty())
        {
          int len = Q.size();
          count++;
          while(len--)
          {
            string temp = Q.front(); Q.pop();
            for(int i = 0; i < 8; i++)
            {
              char c = temp[i];
              for(int j = 0; j < 4; j++)
              {
                if(M[j] == c) continue;
                temp[i] = M[j];
                if(S.find(temp) == S.end()) continue;
                if(V.find(temp) != V.end()) continue;
                if(temp == endGene) return count;
                V.insert(temp);
                Q.push(temp);
              }
              temp[i] = c;
            }
          }
        }
        return -1;
      };

      V.insert(startGene);
      return bfs(startGene);
    }
};

int main()
{
  vector<string> B = {"AACCGGTA", "AACCGCTA", "AAACGGTA" };
  cout << Solution().minMutation("AACCGGTT", "AAACGGTA", B) << endl;
  return 0;
}

