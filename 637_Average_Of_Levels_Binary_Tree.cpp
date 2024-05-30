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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> R;
        if(root == nullptr) return R;
        queue<TreeNode *> Q;
        Q.push(root);

        while(!Q.empty())
        {
            double sum = 0;
            int len = Q.size();
            for(int i = 0; i< len; i++)
            {
                root = Q.front();
                Q.pop();
                if(root->left) Q.push(root->left);
                if(root->right) Q.push(root->right);
                sum += root->val;
            }
            R.push_back(sum/len);
        }
        return R;
    }
};
