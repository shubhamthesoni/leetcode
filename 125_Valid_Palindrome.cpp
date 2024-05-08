#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
      string F;
      int len = s.length();
      for(int i = 0; i < len; i++)
      {
        switch(s[i])
        {
          case 'A'...'Z': F += (s[i] - 'A' + 'a'); break;
          case 'a'...'z': F += s[i]; break;
          case '0'...'9': F += s[i]; break;
          default: break;
        }
      }

      len = F.length();
      for(int i = 0; i < (len/2); i++)
      {
        if(F[i] != F[len -i-1]) return false;
      }
      return true;
    }
};


int main()
{
  Solution solution; 
  //cout << solution.isPalindrome("A man, a plan, a canal: Panama") << endl;
  cout << solution.isPalindrome(" ") << endl;
  return 0;
}
