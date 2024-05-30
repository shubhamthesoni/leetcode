#include <iostream>

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
    int sumNumbers(TreeNode * root, int number)
    {
      if(root == nullptr) return 0;
      number = number*10 + root->val;
      return max(number, sumNumbers(root->left, number) + sumNumbers(root->right, number));
    }

public:
    int sumNumbers(TreeNode* root) {
      int totalSum = 0;
      return sumNumbers(root, 0);
    }
};


int main()
{
  return 0;
}
