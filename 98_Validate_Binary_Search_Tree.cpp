#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    bool isValidBST(TreeNode * root, int minValue, int maxValue) {
      if(root==nullptr) return true;
      if((root->val < minValue ) || (root->val > maxValue)) return false;
      return (((root->left == nullptr) || ((root->val > INT_MIN) && isValidBST(root->left, minValue, root->val - 1))) &&
              ((root->right == nullptr) || ((root->val < INT_MAX) && isValidBST(root->right, root->val + 1, maxValue)))) ;
    }
public:
    bool isValidBST(TreeNode* root) {
      return isValidBST(root, INT_MIN, INT_MAX);   
    }
};


int main()
{
  TreeNode * T2 = new TreeNode(1);
  TreeNode * T1 = new TreeNode(1, T2, nullptr);
  cout << Solution().isValidBST(T1) << endl;
  return 0;
}
