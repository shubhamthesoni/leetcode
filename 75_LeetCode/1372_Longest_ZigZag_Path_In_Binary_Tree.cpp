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
    int longestZigZag(TreeNode * root, bool left, int height)
    {
        if(root == nullptr) return height;
        int l = longestZigZag(root->left, true, (left == true)?0:height+1);
        int r = longestZigZag(root->right, false, (left==false)?0:height+1);
        return max(l, r);
    }
public:
    int longestZigZag(TreeNode* root) {
        if(root == nullptr) return 0;
        return max(longestZigZag(root->left, true, 0), longestZigZag(root->right, false, 0));
    }
};
