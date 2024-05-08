#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
#if 0
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
#endif
      int start = 0, end = s.length() -1;
      while(start <= end)
      {
        if(!isalnum(s[start])) { start++; continue; }
        if(!isalnum(s[end])) { end--; continue; }
        if(tolower(s[start++]) != tolower(s[end--])) return false;
      }

      return true;
    }
};


int main()
{
  Solution solution; 
  cout << solution.isPalindrome("A man, a plan, a canal: Panama") << endl;
  cout << solution.isPalindrome(" ") << endl;
  return 0;
}
