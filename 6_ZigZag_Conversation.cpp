#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
      vector<string> data(numRows);
      int index = 0;
      int inc = 1;
      int len = s.length();
      for(int i = 0; i < len ; i++)
      {
        data[index].push_back(s[i]);
        index += inc;
        if(index== 0) inc = 1;
        else if(index == (numRows-1)) inc = -1; 
      } 
      
      string result;
      for(int i =0 ; i < data.size(); i++) result.append(data[i]);
      return result;
    }
};


int main()
{
  cout << Solution().convert("PAYPALISHIRING", 3) << endl;
  return 0;
}
