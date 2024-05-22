#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
#if 0
      map<char, char> M;
      map<char, char> N;
      int len1 = s.length();
      int len2 = t.length();
      if(len1 != len2) return false;
      for(int i = 0; i < len1; i++)
      {
        if(M.find(s[i]) != M.end())
        {
          if(M[s[i]] != t[i]) return false;
        }
        if(N.find(t[i]) != N.end())
        {
          if(N[t[i]] != s[i]) return false;
        }
        M[s[i]] = t[i]; N[t[i]] = s[i]; 
      }
#endif
      int I1[255] = {0};
      int I2[255] = {0};
      int len1 = s.length();
      int len2 = t.length();
      if(len1 != len2) return false;
      for(int i = 0; i < len1; i++)
      {
        if(I1[s[i]] != I2[t[i]]) return false;
        I1[s[i]] = i+1;
        I2[t[i]] = i+1;
      }
      return true; 
    }
};


int main()
{
  cout << Solution().isIsomorphic("egg", "add")<< endl;
  cout << Solution().isIsomorphic("foo", "bar")<< endl;
  cout << Solution().isIsomorphic("paper", "title")<< endl;
  cout << Solution().isIsomorphic("badc", "baba")<< endl;
  return 0;
}
