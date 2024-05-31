/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    map<Node *, Node *> M;

public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        if(M.find(node) != M.end()) return M[node];
        Node * newNode = new Node(node->val);
        M[node] = newNode;
        for(Node * temp : node->neighbors)
        {
            Node * dummy = cloneGraph(temp);
            if(dummy != nullptr)
            newNode->neighbors.push_back(dummy);
        }        
        return newNode;
    }
};
