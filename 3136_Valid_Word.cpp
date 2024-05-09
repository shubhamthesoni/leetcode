#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    bool isValid(string word) {
      bool containsVowel = false;
      bool containsConsonant = false;
      string V("aeiou");
      int count=0;
      for(char data : word)
      {
        switch(data)
        {
          case 'A'...'Z':
          case 'a'...'z':
            if(V.find(tolower(data))!= string::npos) containsVowel = true;
            else containsConsonant = true;
            break;
          case '0'...'9': break;
          default: return false;
        }
        cout << "Count : "<<count<<" Vowel : "<<containsVowel<<" Consonant : "<<containsConsonant<<endl; 
        count++;
      }
      cout << "Count : "<<count<<" Vowel : "<<containsVowel<<" Consonant : "<<containsConsonant<<endl; 
      return ((count>2) && containsVowel && containsConsonant);
    }
};


int main()
{
  Solution solution;
  cout << solution.isValid("234Adas")<<endl;
  cout << solution.isValid("b3")<<endl;
  cout << solution.isValid("a3$e")<<endl;
  cout << solution.isValid("Hor")<<endl;
  return 0;
}

