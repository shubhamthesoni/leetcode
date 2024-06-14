#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>

using namespace std;

#if 1
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
      //map<int, vector<int>> M;
      int m = spells.size();
      int n = potions.size();
      //vector<int> S(spells.begin(), spells.end());
      //vector<int> C(m, 0);
      //for(int i = 0; i < m; i++) M[spells[i]].push_back(i);

      //sort(spells.begin(), spells.end());
      sort(potions.begin(), potions.end());

      function<void(int)> evaluate = [&](int smid) {
        int pmid = 0;
        int low = 0;
        int high = n-1;

        while((low <= high))
        {
          pmid = low + (high - low)/2;
          long long product = (unsigned long long) spells[smid]*potions[pmid];
          if(product >= success)
          {
            high = pmid -1;
          }  
          else
          {
            low = pmid + 1;
          }
        }
        //cout << "With "<<S[smid]<<"Product Match "<<potions[high] << " : " <<low<<":"<<pmid<<":"<<high << endl;

        spells[smid] = (n - high -1);
        //cout << "C[smid] : "<<C[smid]<<" : "<<n<< " : "<<high<<" : "<<(n - high - 1)<<endl;
        //evaluate(sx, smid-1, max(0,high), py);
        //evaluate(smid+1,sy, px, high);
      };

      //evaluate(0, m-1, 0, n-1);
      
      for(int i = 0; i < m; i++)
      {
        evaluate(i);
        //if((i > 0) && (S[i] == S[i-1])) continue;
        //for(int x: M[S[i]]) spells[x] = C[i];
      } 

      return spells;
    }
};
#else


class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
      //map<int, vector<int>> M;
      int m = spells.size();
      int n = potions.size();
      //vector<int> S(spells.begin(), spells.end());
      //vector<int> C(m, 0);
      //for(int i = 0; i < m; i++) M[spells[i]].push_back(i);

      //sort(S.begin(), S.end());
      sort(potions.begin(), potions.end());

      function<void(int, int, int)> evaluate = [&](int smid, int low, int high) {
        //int low = 0;
        //int high = n-1;
        int pmid = 0;

        while((low <= high))
        {
          pmid = low + (high - low)/2;
          unsigned long long product = (long long) spells[smid]*potions[pmid];
          if(product >= success)
          {
            high = pmid -1;
          }
          else
          {
            low = pmid + 1;
          }
        }
        //cout << "With "<<S[smid]<<"Product Match "<<potions[high] << endl;

        spells[smid] = (n - high -1);
        //evaluate(sx, smid-1, max(0,high), py);
        //evaluate(smid+1,sy, px, high);
      };

      //evaluate(0, m-1, 0, n-1);

        int low = 0;
        int high = n-1;
      for(int i = 0; i < m; i++)
      {
        //if((i > 0) && (S[i] == S[i-1])) continue;
        //for(int x: M[S[i]]) spells[x] = C[i];
        evaluate(i, low, high);
      }

      return spells;
        
    }
};
#endif

int main()
{
  vector<int> S = {39,34,6,35,18,24,40};
  vector<int> P = {27,37,33,34,14,7,23,12,22,37};
  S = Solution().successfulPairs(S, P, 43);
  for(int x : S) cout << x << " ";
  cout << endl;
  return 0;
}
