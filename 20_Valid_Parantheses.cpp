#include <iostream>
#include <string>
#include <stack>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
      int len = s.length();
      stack<char> S;
      for(int i = 0; i < len; i++)
      {
        if((s[i] == '}') && (!S.empty()) && (S.top() == '{')) { S.pop(); continue; }
        if((s[i] == ']') && (!S.empty()) && (S.top() == '[')) { S.pop(); continue; }
        if((s[i] == ')') && (!S.empty()) && (S.top() == '(')) { S.pop(); continue; }
        else S.push(s[i]);
      }
      return S.empty();
    }
};


int main()
{
  Solution solution;
  cout << solution.isValid("{{}}[]")<<endl;
  return 0;
}
