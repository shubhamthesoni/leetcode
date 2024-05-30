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
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> R;
      if(root == nullptr) return R;
      queue<TreeNode *> Q;
      Q.push(root);

      while(!Q.empty())
      {
        vector<int> T;
        int len = Q.size();
        while(len--)
        {
          root = Q.front(); Q.pop(); 
          T.push_back(root->val);
          if(root->left) Q.push(root->left);
          if(root->right) Q.push(root->right);
        }
        R.push_back(T);
      }
      return R;  
    }
};

int main()
{
  return 0;
}
