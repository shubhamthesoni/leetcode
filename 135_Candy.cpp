#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int total = 0;
        int len = ratings.size();
        vector<int> C(len, 0);
        C[0] = 1;
        for(int i = 1; i < len; i++)
        {
            if(ratings[i] > ratings[i-1]) {C[i] = C[i-1] + 1;}
            else {C[i] = 1;}
        }
        for(int i = len-2; i >= 0; i--)
        {
          if(ratings[i] > ratings[i+1]) { C[i] = max(C[i], C[i+1]+1); } 
          total += C[i]; 
        }
        return total + C[len-1];
    }
};

int main()
{
  vector<int> V = { 4,3,0,1,2,3,4,5,4,0,1,2,5,4,3,2,1,0,6,7};
  cout << Solution().candy(V) << endl;
  return 0;
}
