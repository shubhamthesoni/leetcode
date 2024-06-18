struct TrieNode {
    TrieNode* childNode[26];
    bool wordEnd;
    string s;

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
    currentNode->s = key;
    currentNode->wordEnd = 1;
}

void find_end_string(vector<string> & R, int & count, TrieNode * root)
{
    if(count == 0) return ;
    if(root == nullptr) return;

    if(root->wordEnd) { R.push_back(root->s); count--; }
    if(count == 0) return;

    for(int i = 0; i < 26; i++)
    {
        if(root->childNode[i] != NULL) find_end_string(R, count, root->childNode[i]);
        if(count == 0) return;
    }
    return ;
}

vector<string> search_key(TrieNode* root, string& key)
{
    vector<string> R;
    TrieNode* currentNode = root;
    for (auto c : key) {
        if (currentNode->childNode[c - 'a'] == NULL) {
            return R;;
        }
        currentNode = currentNode->childNode[c - 'a'];
    }

    int count = 3;
    find_end_string(R, count, currentNode);
    return R;

}

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode *root = new TrieNode();
        for(string s : products) insert_key(root, s);

        vector<vector<string>> R;
        string temp;
        for(char s : searchWord)
        {
            temp.push_back(s);
            R.push_back(search_key(root, temp));
        }

        return R;
    }
};
