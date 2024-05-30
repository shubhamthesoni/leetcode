#include <iostream>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#if 0
class BSTIterator {
    TreeNode * head ;
  
    TreeNode * buildTree(TreeNode * root)
    {
      if(root == nullptr) return nullptr;
      TreeNode * head = new TreeNode(-1);
      TreeNode * dummy = head;
      head->right = buildTree(root->left);
      while(head->right != nullptr) head = head->right;
      head->right = root;
      head = head->right;
      head->right = buildTree(root->right);
      head = dummy;
      dummy = head->right;
      delete head;
      return dummy;
    }


public:
    BSTIterator(TreeNode* root) {
      TreeNode * head = new TreeNode(-1);
      head->next = buildTree(root); 
    }
    
    int next() {
      if(head->right != nullptr) { head = head->right; return head->val; }
      return -1; 
    }
    
    bool hasNext() {
      return (head->right != nullptr);  
    }
};
#endif

class BSTIterator {
  stack<TreeNode *> S;

public : 
  BSTIterator(TreeNode* root) {
    while(root)
    {
      S.push(root);
      root = root->left;
    }
  }

  int next() {
    TreeNode * root = S.top();
    int val = root->val;
    S.pop();
    root = root->right;
    while(root) { S.push(root); root = root->left; }
    return val;
  }

  bool hasNext() {
    return (!S.empty());
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{
  return 0;
}
