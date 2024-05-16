#include <iostream>


using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
      switch(root->val)
      {
        case 2:
          return (evaluateTree(root->left) || evaluateTree(root->right));
          break;
        case 3:
          return (evaluateTree(root->left) && evaluateTree(root->right));
          break;
        default:
          return (root->val == 0) ? false:true;
      } 
      return true;
    }
};


int main()
{

  TreeNode * T5 = new TreeNode(1);
  TreeNode * T4 = new TreeNode(0);
  TreeNode * T3 = new TreeNode(3, T4, T5);
  TreeNode * T2 = new TreeNode(1);
  TreeNode * T1 = new TreeNode(2, T2, T3);

  cout << Solution().evaluateTree(T1) << endl;
  return 0;
}
