#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {

public:
    Node* connect(Node* root) {
      if(root == nullptr) return root;
      queue<Node *> Q;
      Node * dummy = root;

      Q.push(root);
      int len = 0;
     
      Node * prev = nullptr;

      while(!Q.empty())
      {
	if(len == 0) { prev = nullptr; len = Q.size(); }

        root = Q.front();
        Q.pop();

        if(prev) prev->next = root;
        prev = root;
        
        if(root->left) 
          Q.push(root->left);
        if(root->right) 
          Q.push(root->right);

        len--;
      }
      return dummy;
    }
};

int main()
{
  return 0;
}
