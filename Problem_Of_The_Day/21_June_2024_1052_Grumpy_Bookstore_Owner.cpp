#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
       int len = customers.size();
       int totalS = 0;
       int maxS = INT_MIN;
       int currS = 0;
       for(int i = 0; i < len; i++)
       {
         if(grumpy[i] == 0) totalS += customers[i];
         else if(i < minutes) currS += customers[i];
       }

       maxS = currS;
       for(int i = minutes; i < len; i++)
       {
         currS += (grumpy[i]*customers[i]) - (grumpy[i-minutes]*customers[i-minutes]);
         if(currS > maxS) maxS = currS;
       }
       return totalS + maxS; 
    }
};


int main()
{
  vector<int> C = {1,0,1,2,1,1,7,5};
  vector<int> G = {0,1,0,1,0,1,0,1};

  cout << Solution().maxSatisfied(C, G, 3) << endl;
  return 0;
}
