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

string search_key(TrieNode* root, string& key)
{
    string result;
    TrieNode* currentNode = root;
    for (auto c : key) {
        if (currentNode->childNode[c - 'a'] == NULL) {
            return (currentNode->wordEnd == true)?result:key;
        }
        if(currentNode->wordEnd == true) return result;
        result.push_back(c);
        currentNode = currentNode->childNode[c - 'a'];
    }
    return (currentNode->wordEnd == true) ? result: key;
}

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode *root = new TrieNode();
        for(string s: dictionary)
        {
            insert_key(root, s);
        }

        stringstream ss(sentence);
        string word;
        string result;

        while(ss>>word)
        {
            result.append(search_key(root, word));
            result.push_back(' '); 
        }
        result.pop_back();
        return result;
    }
};
