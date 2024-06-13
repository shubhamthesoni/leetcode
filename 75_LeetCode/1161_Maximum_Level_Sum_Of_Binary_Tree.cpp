/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
      queue<TreeNode *> Q;
      if(root == nullptr) return 0;

      Q.push(root);
      int size = 0;
      int sum = 0;
      int max_sum = INT_MIN;
      int curr_level = 0;
      int max_level = 0;    

      while(!Q.empty())
      {
        curr_level++;
        sum = 0;
        size = Q.size();
        while(size--)
        {
          TreeNode * temp = Q.front(); Q.pop();
          sum += temp->val;
          if(temp->left) Q.push(temp->left);
          if(temp->right) Q.push(temp->right);
        }
        if(sum > max_sum) { max_sum = sum; max_level = curr_level; }
      }      
      return max_level;
    }
};
