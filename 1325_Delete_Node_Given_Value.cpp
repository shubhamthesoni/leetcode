#include<iostream>

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
public:

    void display(TreeNode * root)
    {
      if(root == nullptr) return;
      if(root->left != nullptr) display(root->left);
      cout << root->val << " " ;
      if(root->right != nullptr) display(root->right);
      return ;
    }


    TreeNode* removeLeafNodes(TreeNode* root, int target) {
      if(root == nullptr) return root;
      if(root->left != nullptr) root->left = removeLeafNodes(root->left, target);
      if(root->right != nullptr) root->right = removeLeafNodes(root->right, target);
      if((root->left == nullptr) && (root->right == nullptr) && (root->val == target)) { delete root; return nullptr; }
      return root;
    }
};

int main()
{
  TreeNode * T8 = new TreeNode(2);
  TreeNode * T7 = new TreeNode(2);
  TreeNode * T6 = new TreeNode(2, nullptr, T8);
  TreeNode * T5 = new TreeNode(3);
  TreeNode * T4 = new TreeNode(2, T7, nullptr);
  TreeNode * T3 = new TreeNode(5, nullptr, T6);
  TreeNode * T2 = new TreeNode(2, T4, T5);
  TreeNode * T1 = new TreeNode(4, T2, T3);

  T1 = Solution().removeLeafNodes(T1, 2);
  Solution().display(T1);
  cout << endl;
  return 0;
}
