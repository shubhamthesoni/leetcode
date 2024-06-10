#include <iostream>
#include <vector>
#include <unordered_set>
#include <functional>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
      int wordlen = beginWord.size();
      unordered_set<string> S;
      unordered_set<string> V;
      unordered_set<char> M[wordlen];
      for(string x : wordList) {
        S.insert(x);
        for(int i = 0; i < wordlen; i++) M[i].insert(x[i]);
      }

      // base case
      if(S.find(endWord) == S.end()) return -1;
      if(beginWord == endWord) return 0;

      function<int(string)> bfs = [&](string beginWord) {

        int count = 0;   
        queue<string> Q;
        Q.push(beginWord);
      
        while(!Q.empty())
        {
          int len = Q.size();
          count++;
          while(len--)
          {
            string temp = Q.front(); Q.pop();
            for(int i = 0; i < wordlen; i++)
            {
              char c = temp[i];
              unordered_set<char>:: iterator itr;
              for(itr = M[i].begin(); itr != M[i].end(); itr++)
              {
                if(*itr == c) continue;
                temp[i] = *itr;
                if(S.find(temp) == S.end()) continue;
                if(V.find(temp) != V.end()) continue;
                if(temp == endWord) return count + 1;
                //cout << "Inserting : " << temp << endl;
                V.insert(temp);
                Q.push(temp);
              }
              temp[i] = c;
            }
          }
        }
        return 0;
      };

      V.insert(beginWord);
      return bfs(beginWord);
    }
};

int main()
{
  vector<string> B = {"hot","dot","dog","lot","log","cog"};
  cout << Solution().ladderLength("hit", "cog" , B) << endl;
  return 0;
}

