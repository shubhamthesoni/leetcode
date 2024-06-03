#include <iostream>

using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();
        int s_index = 0;
        int t_index = 0;
        while((s_index < s_len) && (t_index < t_len))
        {
            if(s[s_index] == t[t_index]) t_index++;
            s_index++;
        }
        return (t_len - t_index); 
    }
};


int main()
{
  cout << Solution().appendCharacters("coaching", "coding") << endl;
  return 0;
}
