#include <iostream>
#include <map>

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
    int height(TreeNode * root, int &diam)
    {
        if(root == nullptr) return 0;
        int left = height(root->left, diam);
        int right = height(root->right, diam);

        diam = max(diam, left+right);
        return 1+max(left, right);
        
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int diam = 0;
        height(root, diam);
        return diam;
    }
#if 0
    int height(TreeNode * root)
    {
        if(root == nullptr) return 0;
        return (1 + max(height(root->left), height(root->right)));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        return max((height(root->left) + height(root->right)), max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
#endif
};

int main()
{
  TreeNode * N4 = new TreeNode(4);
  TreeNode * N5 = new TreeNode(5);
  TreeNode * N3 = new TreeNode(3);
  TreeNode * N2 = new TreeNode(2, N4, N5);
  TreeNode * N1 = new TreeNode(1, N2, N3);

  Solution solution; 
  cout << solution.diameterOfBinaryTree(N1) << endl;
  
  return 0;
}
