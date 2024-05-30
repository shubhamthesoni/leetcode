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

    void inorder(TreeNode * root, int & last, int & mindiff)
    {
      if(root == nullptr) return;
      inorder(root->left, last, mindiff);
      if(last != INT_MAX)
        mindiff = min(mindiff, root->val - last);
      last = root->val;
      inorder(root->right, last, mindiff);
    }

public:
    int getMinimumDifference(TreeNode* root) {
      int last = INT_MAX;
      int minDiff = INT_MAX;
      inorder(root, last, minDiff);
      return minDiff;
    }
};


int main()
{
  TreeNode * N6 = new TreeNode(6);
  TreeNode * N3 = new TreeNode(3);
  TreeNode * N1 = new TreeNode(1);
  TreeNode * N2 = new TreeNode(2, N1, N3);
  TreeNode * N4 = new TreeNode(4, N2, N6);
  
  cout << Solution().getMinimumDifference(N4) << endl;
  return 0;
}
