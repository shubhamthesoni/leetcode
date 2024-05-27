#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        sort(strs.begin(), strs.end());
        int len = strs.size();
        int min_len = min(strs[0].length(), strs[len-1].length());
        for(int i = 0 ; i < min_len; i++)
        {
            if(strs[0][i]!=strs[len-1][i]) return result;
            result += strs[0][i];
        }
        return result;
    }
};


int main()
{
  vector<string> V = { "flower","flow","flight" };
  cout << Solution().longestCommonPrefix(V) << endl;
  return 0;
}
