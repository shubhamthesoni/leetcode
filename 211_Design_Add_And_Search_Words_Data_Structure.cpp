#include <iostream>

using namespace std;

struct TrieNode {
    TrieNode* childNode[26];
    bool wordEnd;

    TrieNode()
    {
        wordEnd = false;
        for (int i = 0; i < 26; i++) {
            childNode[i] = NULL;
        }
    }
};

void insert_key(TrieNode* root, string& key)
{
    TrieNode* currentNode = root;
    for (auto c : key) {
        if (currentNode->childNode[c - 'a'] == NULL) {
            TrieNode* newNode = new TrieNode();
            currentNode->childNode[c - 'a'] = newNode;
        }
        currentNode = currentNode->childNode[c - 'a'];
    }
    currentNode->wordEnd = 1;
}

bool search_key(TrieNode* root, string& key, int start)
{
    TrieNode* currentNode = root;
    if(key.length() == start) return (currentNode->wordEnd == true);

    if(key[start] != '.')
    {
      if(currentNode->childNode[key[start] - 'a'] == NULL) {
            return false;
      }
      return search_key(currentNode->childNode[key[start] - 'a'], key, start+1);
    }
 
    bool result = false;

    for(int i = 0; i < 26; i++)
    {
      if(currentNode->childNode[i] == NULL) continue;
      result |= search_key(currentNode->childNode[i], key, start+1);
      if(result == true) return true;
    }

    return result;
}

class WordDictionary {
    TrieNode * root = nullptr;
public:
    WordDictionary() {
      root = new TrieNode();
    }
    
    void addWord(string word) {
      insert_key(root, word);  
    }
    
    bool search(string word) {
      return search_key(root, word, 0);
    }
};

int main()
{
  WordDictionary wordDictionary;
  wordDictionary.addWord("bad");
  wordDictionary.addWord("dad");
  wordDictionary.addWord("mad");
  cout << wordDictionary.search("pad") << endl;
  cout << wordDictionary.search("bad") << endl; 
  cout << wordDictionary.search(".ad") << endl; 
  cout << wordDictionary.search("b..") << endl; 
  return 0;
}



