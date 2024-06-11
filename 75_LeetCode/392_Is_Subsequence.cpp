#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
      int i=0, j=0;
      for(i=0, j=0; i<s.length(), j<t.length(); )
      {
        if(s[i] == t[j]) {i++; j++; }
        else {j++;}
      }
      if(i == s.length()) return true;
      else return false;

    }
};
