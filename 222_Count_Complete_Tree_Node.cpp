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
    int findDiff(TreeNode * root, int height, int & maxTotal)
    {
      if(root == nullptr) return 0;
      int count = (root->left == nullptr) +  (root->right == nullptr);
      if(height == 1) { maxTotal -= count; return count; }

      count = findDiff(root->right, height -1, maxTotal);
      if(count < 2) return 0;
      count = findDiff(root->left, height -1, maxTotal);
      return count;
    }

public:
    int countNodes(TreeNode* root) {
       int maxTotal = 0;
       int height = 0;
       TreeNode * temp = root;
       while(temp) { temp = temp->left; height++; }
       maxTotal = (1<<height) - 1;

       findDiff(root, height-1, maxTotal);
       return maxTotal;

    }
};

int main()
{
  TreeNode * N6 = new TreeNode(6);
  TreeNode * N5 = new TreeNode(5);
  TreeNode * N4 = new TreeNode(4);
  TreeNode * N3 = new TreeNode(3, N6, nullptr);
  TreeNode * N2 = new TreeNode(2, N4, N5);
  TreeNode * N1 = new TreeNode(1, N2, N3);
  
  cout << Solution().countNodes(N1) << endl;

  return 0;
}
