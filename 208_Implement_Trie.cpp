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

bool search_key(TrieNode* root, string& key, bool full)
{
    TrieNode* currentNode = root;
    for (auto c : key) {
        if (currentNode->childNode[c - 'a'] == NULL) {
            return false;
        }
        currentNode = currentNode->childNode[c - 'a'];
    }

    if(full == false) return true;
    return (currentNode->wordEnd == true);
}


class Trie {
    TrieNode * root = nullptr;
public:
    Trie() {
      root = new TrieNode();
    }
    
    void insert(string word) {
      insert_key(root, word);  
    }
    
    bool search(string word) {
      return search_key(root, word, true);
    }
    
    bool startsWith(string prefix) {
      return search_key(root, word, false);  
    }
};
