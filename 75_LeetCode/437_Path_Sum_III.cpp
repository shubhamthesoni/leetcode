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
    int pathSum(TreeNode * root, int targetSum, long long currSum, map<long long, int>& M)
    {
        if(root == nullptr) return 0;
        currSum += root->val;
        int count = M[currSum - targetSum];
        M[currSum]++;
        count += pathSum(root->left, targetSum, currSum, M);
        count += pathSum(root->right, targetSum, currSum, M);
        M[currSum]--;
        return count;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        map<long long, int> M;
        M[0] = 1;
        return pathSum(root, targetSum, 0, M);
    }
};
