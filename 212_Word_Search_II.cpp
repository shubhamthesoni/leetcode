#include <iostream>
#include <vector>
#include <functional>

using namespace std;

struct TrieNode {
    TrieNode* childNode[26];
    int wordIndex;

    TrieNode()
    {
        wordIndex = -1;
        for (int i = 0; i < 26; i++) {
            childNode[i] = NULL;
        }
    }
};

void insert_key(TrieNode* root, string& key, int index)
{
    TrieNode* currentNode = root;
    for (auto c : key) {
        if (currentNode->childNode[c - 'a'] == NULL) {
            TrieNode* newNode = new TrieNode();
            currentNode->childNode[c - 'a'] = newNode;
        }
        currentNode = currentNode->childNode[c - 'a'];
    }
    currentNode->wordIndex = index;
}

class Solution {
    TrieNode * root = nullptr;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      vector<string> result;
         
      root = new TrieNode();

      int m = board.size();
      int n = board[0].size();
 
      for(int i = 0; i < words.size(); i++) insert_key(root, words[i], i);

      function<void(TrieNode *, int, int)> dfs = [&](TrieNode * node, int x, int y) {
        int charIndex = board[x][y] - 'a';
        if(node->childNode[charIndex] == NULL) return;
 
        node = node->childNode[charIndex];
        if(node->wordIndex != -1) { result.push_back(words[node->wordIndex]); node->wordIndex = -1; }  

        int direction[5] = { 0, 1, 0, -1, 0};
        char temp = board[x][y];
        board[x][y] = '#';
        for(int i = 0; i < 4; i++)
        {
          int xx = x + direction[i], yy = y + direction[i+1];
          if((xx >= 0) && (xx < m) && (yy >= 0) && (yy < n) && (board[xx][yy] != '#')) dfs(node, xx, yy);
        }
        board[x][y] = temp;
      };

      
      for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
          dfs(root, i, j);

      return result;
    }
};


int main()
{
  vector<vector<char>> B = {{'o','a','a','n'}, {'e','t','a','e'}, {'i','h','k','r'}, {'i','f','l','v'}};
  vector<string> W = {"oath", "pea","eat","rain"};
  W = Solution().findWords(B, W);
  for(string S: W) cout << S << endl;
  return 0;
}
