#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
      int len1 = word1.length();
      int len2 = word2.length();

      string result;
      int i = 0, j = 0;
      while(i<len1 && j < len2)
      {
        if(i==j) result.push_back(word1[i++]);
        else result.push_back(word2[j++]);
      }
      while(i<len1) result.push_back(word1[i++]);
      while(j<len2) result.push_back(word2[j++]);
      cout << word1 << " " << word2<<endl;
      return result;
    }
};


int main()
{
  cout << Solution().mergeAlternately("abc", "pqr") << endl;
  cout << Solution().mergeAlternately("ab", "pqrs") << endl;
  cout << Solution().mergeAlternately("abcde", "pq") << endl;
  return 0;
}
