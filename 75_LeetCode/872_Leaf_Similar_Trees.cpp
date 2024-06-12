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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> V1, V2;
        
        function<void(TreeNode *, vector<int> &)> dfs = [&](TreeNode * node, vector<int> & leaf) {
            if(node == nullptr) return;

            if((node->left == nullptr) && (node->right == nullptr))
            {
                leaf.push_back(node->val);
                return;
            }

            if(node->left != nullptr) dfs(node->left, leaf);
            if(node->right != nullptr) dfs(node->right, leaf);
            return; 
        };

        dfs(root1, V1);
        dfs(root2, V2);

        if(V1.size() != V2.size()) return false;
        for(int i = 0; i < V1.size(); i++)
        {
            if(V1[i] != V2[i]) return false;
        }
        return true;
    }
};
