#include <iostream>
#include <vector>
#include <queue>

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;
        queue<TreeNode *> Q;
        Q.push(root);

        while(!Q.empty())
        {
          int size = Q.size();
          result.push_back(Q.front()->val);
          while(size--)
          {
            root = Q.front();
            Q.pop();
            if(root->right) Q.push(root->right);
            if(root->left) Q.push(root->left);
          }
        }
        return result;
    }
};


int main()
{
  return 0;
}
