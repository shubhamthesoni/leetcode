#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
      map<int, int> M;
      int maxF = 0;
      int len = fruits.size();
      int j = 0;
      for(int i = 0; i < len; i++)
      {
        if((M.size() < 2) || (M.find(fruits[i]) != M.end()))
        {
          M[fruits[i]]++;
          cout << "M[fruits["<<i<<"]] = "<<M[fruits[i]]<<endl;
        }
        else
        {
          int sum = 0;

          for(auto itr : M) { cout << itr.first << " has value "<<itr.second<<endl; sum += itr.second; }
          while(M.size() == 2) { M[fruits[j]]--; if(M[fruits[j]]==0) M.erase(fruits[j]); j++; }

          maxF = max(maxF, sum);
          M[fruits[i]]++;
        } 
      }

      int sum = 0;
      for(auto itr : M) { cout << itr.first << " has value "<<itr.second<<endl; sum += itr.second; }

      return max(maxF, sum); 
    }
};

int main()
{
  Solution solution;
  //vector<int> V = {1,2,3,2,2};
  //vector<int> V = {0,1,2,2};
  vector<int> V = {0,1,6,6,4,4,6};
  cout << solution.totalFruit(V)<<endl;
  return 0;
}
