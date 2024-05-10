#include <iostream>
#include <tuple>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
      priority_queue<tuple<float, int, int>> PQ;

      int len = arr.size();
      for(int i = 0; i < len; i++)
      {
        for(int j = i+1; j < len; j++)
        {
          //cout << "Inserting "<<(float (arr[i]))/(float (arr[j])) << " at "<<i<<" "<<j<<endl;
          PQ.push(make_tuple((float (arr[i]))/(float (arr[j])), i, j));
          if(PQ.size() > k) { 
            //tuple<float, int, int> T = PQ.top(); 
            PQ.pop(); 
            //cout << "Removed from PQ is "<<float (get<0>(T))<<" At index "<<get<1>(T)<<" "<<get<2>(T)<<endl;
          }
        }
      }

      tuple<float, int, int> T = PQ.top();

      return {arr[get<1>(T)], arr[get<2>(T)]};        
    }
};


int main()
{
  vector<int> V  = {1,2,3,5};
  Solution solution;
  
  vector<int> R = solution.kthSmallestPrimeFraction(V, 3);

  cout << R[0] << " " << R[1] << endl;

  return 0;
}
