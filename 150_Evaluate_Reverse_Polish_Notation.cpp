#include <iostream>
#include <vector>
#include <stack>


using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      int len = tokens.size();
      stack<int> S;
      for(int i = 0; i < len; i++)
      { 
        int left;
        int right;
        if(tokens[i].length() == 1)
        {
          switch(tokens[i][0])
          {
            case '+':
              right = S.top(); S.pop(); 
              left  = S.top(); S.pop();
              S.push(left+right);
              break;
            case '-':
              right = S.top(); S.pop(); 
              left  = S.top(); S.pop();
              S.push(left-right);
              break;
            case '/':
              right = S.top(); S.pop(); 
              left  = S.top(); S.pop();
              S.push(left/right);
              break;
            case '*':
              right = S.top(); S.pop(); 
              left  = S.top(); S.pop();
              S.push(left*right);
              break;
            default: S.push(stoi(tokens[i])); break;
          }
        }
        else
        {
          S.push(stoi(tokens[i]));
        }
      }
      return S.top();        
    }
};

int main()
{
  vector<string> V = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
  cout << Solution().evalRPN(V) << endl;
  return 0;
}
