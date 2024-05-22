#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
      map<char, string> M;
      map<string, char> N;
      stringstream ss(s);
      string words;
      int i = 0;
      while( ss >> words)
      {
        if(M.find(pattern[i]) != M.end()) 
        { 
          if(M[pattern[i]] != words) return false;
        }
        if(N.find(words) != N.end()) 
        { 
          if(N[words] != pattern[i]) return false; 
        }
        N[words] = pattern[i];
        M[pattern[i]] = words;
        i++;
      }    
      return true;
    }
};


int main()
{
  cout << Solution().wordPattern("abba", "dog dog dog dog") << endl;
  return 0;
}
