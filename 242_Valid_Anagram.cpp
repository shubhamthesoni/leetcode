#include<iostream>
#include<map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
      map<char, int> C;
      for(int i = 0; i < s.length(); i++) C[s[i]]++;
      for(int i = 0; i < t.length(); i++)
      {
        if(C[t[i]] <= 0) return false;
        C[t[i]]--;
      }
      return true; 
    }
};


int main()
{
  Solution solution;
  cout << solution.isAnagram("anagram","nagaram")<<endl;
  cout << solution.isAnagram("rat","car")<<endl;

  return 0;
}
