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
     int maxPathSum(TreeNode * root, int & maxSum)
     {
       if(root == nullptr) return 0;
       int left_sum = max(maxPathSum(root->left, maxSum), 0);
       int right_sum = max(maxPathSum(root->right, maxSum), 0);

       maxSum = max(maxSum, left_sum + right_sum + root->val);
       return root->val + max(left_sum, right_sum);
     }    

public:
    int maxPathSum(TreeNode* root) {
      int maxSum = INT_MIN;
      maxPathSum(root, maxSum);
      return maxSum;
    }
};

int main()
{
  return 0;
}
