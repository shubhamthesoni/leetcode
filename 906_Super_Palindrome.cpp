#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

class Solution {
    map<long long, bool> M;
public:

    long long reverse(long long X)
    {
      long long result = 0;
      while(X)
      {
        result = result*10 + X%10;
        X = X/10;
      }
      return result;
    }


    bool isPalindrome(long long X)
    {
      return (X==reverse(X));
    }

    int superpalindromesInRange(string left, string right) {

      long long start = stoll(left);
      long long end   = stoll(right);

      int magic = 100000;
      int len = 0;
      long long V;

      int count = 0;

      string S = "";
      for(int i = 1; i < magic; i++)
      {
        S = to_string(i);
        len = S.length();
        for(int j = len -2; j >= 0; j--) S += S.at(j);
       
        V = stoll(S);
        V = V*V;
        if(V > end) break;    
        if((V >= start) && isPalindrome(V)) count++;
      }

      for(int i = 1; i < magic; i++)
      {
        S = to_string(i);
        len = S.length();
        for(int j = len - 1; j >= 0; j--) S += S.at(j);
       
        V = stoll(S);
        V = V*V;
        if(V > end) break;    
        if((V >= start) && isPalindrome(V)) count++;
      }

      return count;
    }
};


int main()
{
  Solution solution;
  cout << solution.superpalindromesInRange("4", "1000")<<endl;
  cout << solution.superpalindromesInRange("9944094036", "431375128285413")<<endl;
  cout << solution.superpalindromesInRange("40000000000000000", "50000000000000000")<<endl;
  return 0;
}
