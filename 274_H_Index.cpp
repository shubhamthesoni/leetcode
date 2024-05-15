#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
      sort(citations.begin(), citations.end(), greater<int>());
      int len = citations.size();
      int index = 0;
      for(index = 0; index < len; index++)
      {
        if(citations[index] < (index+1)) break;
      }
      return index;
    }
};

int main()
{
  //vector<int> V = {3,0,6,1,5};
  vector<int> V = {1,3,1};
  cout << Solution().hIndex(V) << endl;
  return 0;
}

