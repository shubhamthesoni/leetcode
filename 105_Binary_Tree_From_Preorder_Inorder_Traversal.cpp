#include <iostream>
#include <vector>
#include <unordered_map>

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
    int preindex;
    unordered_map<int, int>M;
    TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder, int start, int end) {
      if(end < start) return NULL;
      TreeNode * node = new TreeNode(preorder[preindex++]);
      if(start == end) return node;

      int index = M[node->val];
      //for(index = start; index < end; index++) if(inorder[index] == node->val) break;
      node->left  = buildTree(preorder, inorder, start, index-1);
      node->right = buildTree(preorder, inorder, index+1, end);
      return node;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      int len = inorder.size();
      for(int i = 0; i < len; i++) M[inorder[i]] = i;
      preindex = 0;
      return buildTree(preorder, inorder, 0, len-1);
    }

};

int main()
{
  vector<int> Pre = {3,9,20,15,7};
  vector<int> In  = {9,3,15,20,7};

  TreeNode * T = Solution().buildTree(Pre, In);

  return 0;
}
