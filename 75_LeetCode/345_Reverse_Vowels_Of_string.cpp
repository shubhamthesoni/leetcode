#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
      vector<char> V = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
      unordered_set<char> S(V.begin(), V.end());

      int len = s.length();
      int start = 0;
      int end = len-1;
      while(start <= end)
      {
        if(S.find(s[start]) == S.end()) { start++; continue; }
        if(S.find(s[end]) == S.end()) { end--; continue; }
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
      }
      return s;
    }
};

