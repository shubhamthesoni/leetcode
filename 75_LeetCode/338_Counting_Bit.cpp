#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) 
    {
      vector<int> bits;
      int pow2 = 2;
      int i, j=0;

      bits.push_back(0);

      if(n==0) return bits;
      
      for(i=1; i<=n; i++)
      {
        bits.push_back(bits[i/2] + i%2);
      }

#if 1
      for(i=0; i<=n; i++)
      {
        cout << i << " -> " << bits[i] << endl;
      }
#endif
      return bits;
    }
};

int main()
{
  int N;
  Solution solution;

  cin >> N;
  solution.countBits(N);

  return 0;
}
