#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
      string temp = word;
      int k = 0;
      while(sequence.find(temp) != string::npos) {k++; temp += word;}
      return k;
    }
};


int main()
{
  Solution solution;
  cout << solution.maxRepeating("ababc", "ab");
  return 0;
}
