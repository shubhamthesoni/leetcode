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
    int goodNodes(TreeNode * root, int maxval) {
        if(root == nullptr) return 0;
        return (root->val >= maxval) +  goodNodes(root->left, max(root->val, maxval)) + goodNodes(root->right, max(root->val, maxval));
    } 
public:
    int goodNodes(TreeNode* root) {
        return goodNodes(root, INT_MIN);
    }
};
