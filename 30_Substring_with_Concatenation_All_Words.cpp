#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

    bool checkSubstring(string s, unordered_map<string, int> M, int size, int len)
    {
       for(int i = 0; i < size; i++)
       {
         string temp = s.substr(i*len, len);
         if(M.find(temp) == M.end()) return false;
         M[temp]--;
         if(M[temp] < 0) return false; 
       }
       return true;
    }

public:
    
    vector<int> findSubstring(string s, vector<string>& words) {
      vector<int> R;

      int wordSize = words.size();
      int wordLen = words[0].length();

      int total_Window = wordSize * wordLen;
      unordered_map<string, int> M;
      for(string S: words) M[S]++;

      int i = 0;
      while(i+total_Window < s.length())
      {
        if(checkSubstring(s.substr(i, total_Window), M, wordSize, wordLen)) R.push_back(i);
        i++;
      }
      return R;
    }
};

int main()
{
  vector<string> V = { "foo","bar" };
  vector<int> R = Solution().findSubstring("barfoothefoobarman" , V);
  for(int X : R ) cout << X << " ";
  cout << endl;
  return 0;
}
