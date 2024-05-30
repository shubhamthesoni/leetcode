#include <iostream>
#include <climits>
#include <vector>

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

    int inorder(TreeNode * root, int & k)
    {
      if(root == nullptr) return 0;
      int value = inorder(root->left, k);
      if(k==0) return value;
      k--;
      if(k==0) return root->val;
      return inorder(root->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
      return inorder(root, k);
    }
};


int main()
{
  TreeNode * N6 = new TreeNode(6);
  TreeNode * N3 = new TreeNode(3);
  TreeNode * N1 = new TreeNode(1);
  TreeNode * N2 = new TreeNode(2, N1, N3);
  TreeNode * N4 = new TreeNode(4, N2, N6);
  
  cout << Solution().kthSmallest(N4, 5) << endl;
  return 0;
}
