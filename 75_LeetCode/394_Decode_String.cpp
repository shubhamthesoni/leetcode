#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#if 0
class Solution {
public:
    string decodeString(string s) {
      stack<string> S;
      for(char x : s)
      {
        cout << "Checking for "<<x<<" " <<to_string(x)<<endl;

        if(isdigit(x))
        {
          string number(1,x);
          while((!S.empty()) && (isdigit(S.top()[0]))) { number = S.top() + number;  S.pop(); }
          S.push(number);
          continue;
        }

        if(x != ']') { S.push(string(1,x)); continue; }
        string t;
        string p;

        cout << "S.top() "<< S.top() << " With T as "<<t<<endl;        
        while((!S.empty()) && (S.top() != "["))
        {
          t = S.top() + t; S.pop();
          cout << "S.top() "<< S.top() << " With T as "<<t<<endl;        
        }
        
        S.pop();
        int count = stoi(S.top()); S.pop();
        cout << "Inserting Count is "<<count<<endl;
        //reverse(t.begin(), t.end());
        while(count--) p = t + p;
        cout << "Inserting back "<<p<<endl;
        S.push(p);
      }
      string R;
      while(!S.empty()) { R = S.top() + R; S.pop(); }
      return R;       
    }
};
#endif
class Solution {
public:
    string decodeString(string s) {
      stack<string> SS;
      stack<int> SI;

      string R;
      int count = 0;
      for(char c : s)
      {
        if(isdigit(c)) count = count*10 + (c -'0');
        else if(isalpha(c)) R.push_back(c);

        if(c == '[') { SI.push(count); SS.push(R); R=""; count = 0; }
        else if( c== ']')
        {
          count  = SI.top(); SI.pop();
          string T = R;
          while(--count) R.append(T);
          if(!SS.empty()) { R = SS.top() + R; SS.pop(); }

        }
      }
      return R;
    }
};



int main()
{
  cout << Solution().decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef") << endl;
  cout << "zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef" << endl;
  cout << "3[z]2[2[y]pq4[2[jk]e1[f]]]ef" << endl;
  cout << Solution().decodeString("100[a2[c]]") << endl;
  //cout << Solution().decodeString("2[abc]3[cd]ef") << endl;
  return 0;
}
