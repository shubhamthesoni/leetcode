#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int total = 1;
        int curr = 1;
        for(int i = 1; i < ratings.size(); i++)
        {
            if(ratings[i] > ratings[i-1]) {curr = curr+1;}
            else {curr = 1;}
            total += curr;
        }
        return total;
    }
};

int main()
{
  vector<int> V = { 1,0,2};
  cout << Solution().candy(V) << endl;
  return 0;
}
