#include <iostream>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

    int find(TreeNode * root, TreeNode * node, stack<TreeNode *> & Q)
    {
      if(root == nullptr) return 0;
      if(root == node) { Q.push(root); return 1; }
      int found = find(root->left, node, Q);
      if(found) { Q.push(root); return found; }

      found = find(root->right, node, Q);
      if(found) { Q.push(root); } 
      return found;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

#if 0
      if (!root || root == p || root == q) return root;
      TreeNode* left = lowestCommonAncestor(root->left, p, q);
      TreeNode* right = lowestCommonAncestor(root->right, p, q);
      return !left ? right : !right ? left : root;
#endif 


      stack<TreeNode *> P;
      stack<TreeNode *> Q;
      find(root, p, P);
      find(root, q, Q);
   
      TreeNode * result;

      while((!P.empty()) && (!Q.empty()))
      {
        if(P.top() != Q.top()) break;
        result = P.top();
        P.pop(); Q.pop();
      }

      return result;
    }
};


int main()
{
  return 0;
}
