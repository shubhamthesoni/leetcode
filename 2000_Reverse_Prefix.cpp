#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    string reversePrefix(string word, char ch) {
        int len = word.length();
        string result;
        bool found = false;
        int i;
        for(i = 0; i < len; i++)
        {
            result = word[i] + result;
            cout << "Result: " + result +", word[" + to_string(i) + "]: "+ word[i] << endl; 
            if(word[i] == ch) {found = true; break;}    
        }
        if(found)
        {
	    if(len > i)
            result = result + word.substr(i+1, len);
            return result;
        }
        return word;
    }
};


int main()
{
  Solution solution;
  cout << solution.reversePrefix(string("abcdefd"), 'd') << endl;
  return 0;
}
