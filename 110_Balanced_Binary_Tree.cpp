class Solution {
public:
    int getHeight(TreeNode * root) {
        if(root == nullptr) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        if(abs(getHeight(root->left) - getHeight(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
