#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
      int len = s.length();
      stack<pair<int,int>> S;
      long long int sum = 0;
      int sign = 1;
      for(int i = 0; i < len; i++)
      {
        if(isdigit(s[i]))
        {
          int number = 0;
          while((i < len) && (isdigit(s[i])))
          {
            number = number*10 + (s[i]-'0'); i++;
          }
          i--;
          sum = sum + number*sign ;
          sign = 1;
        }
        else if(s[i] == '(') { S.push({sum, sign}); sum = 0; sign = 1; }
        else if(s[i] == ')') { sum = S.top().first + S.top().second*sum; S.pop(); }
        else if(s[i] == '-') sign = -1*sign;
      }
      return sum; 
    }
};

int main()
{
  cout << Solution().calculate("(1+(4+5+2)-3)+(6+8)") << endl;
  return 0;
}
