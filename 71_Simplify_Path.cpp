#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string result; 
        stack<string> S;
        stringstream SS(path);

        string T;
        while(getline(SS, T, '/'))
        {
          if((T==".")||(T.length()==0)) continue;
          if(T == "..") { if(!S.empty()) S.pop(); }
          else { reverse(T.begin(), T.end());  S.push(T); }
        }

#if 0
        size_t found = 0;
        int start = 0;
        while((found = path.find('/', found)) != string::npos)
        {
          string temp = path.substr(start, found-start);
          if((temp.length() == 0)||(temp == "/")|| (temp == "."))
          {
            //Do Nothing
          }
          else if(temp == "..")
          {
            if(!S.empty()) {S.pop(); }
          }
          else
          {
            reverse(temp.begin(), temp.end());
            S.push(temp);
          } 
          found++;
          start = found;
        }
        if(found != path.length())
        {
          string temp = path.substr(start, found-start);
          if((temp.length() == 0)||(temp == "/")|| (temp == "."))
          {
            //Do Nothing
          }
          else if(temp == "..")
          {
            if(!S.empty()) {S.pop(); }
          }
          else
          {
            reverse(temp.begin(), temp.end());
            S.push(temp);
          }

        }
#endif
        if(S.empty()) return "/";        

        while(!S.empty())
        {
          result.append(S.top());
          result.append("/");
          S.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
  cout << Solution().simplifyPath("/home/user/Documents/../Pictures//..././abc/") << endl;
  return 0;
}
