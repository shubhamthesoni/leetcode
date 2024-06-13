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
    TreeNode* deleteNode(TreeNode* root, int key) {
      if(root == nullptr) return root;

      if(root->val > key)
      {
        root->left = deleteNode(root->left, key);
        return root;
      }
      else if(root->val < key)
      {
        root->right = deleteNode(root->right, key);
        return root;
      }

      if(root->left == nullptr)
      {
        TreeNode *temp = root->right;
        delete root;
        return temp;
      }
      else if(root->right == nullptr)
      {
        TreeNode * temp = root->left;
        delete root;
        return temp;
      }

      TreeNode * parent = root;
      TreeNode * temp = root->right;
      while(temp->left != nullptr)
      {
        parent = temp;
        temp = temp->left;
      }

      root->val = temp->val;

      if(parent->left == temp)
      {
        parent->left = temp->right;
        delete temp; 
      }
      else
      {
        parent->right = temp->right;
        delete temp;
      }

      return root;
    }
};
