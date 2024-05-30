#include <iostream>
#include <vector>
#include <unordered_map>
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
    int postindex;
    unordered_map<int, int>M;
    TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder, int start, int end) {
      if(end < start) return NULL;
      TreeNode * node = new TreeNode(postorder[postindex--]);
      if(start == end) return node;

      int index = M[node->val];
      //for(index = start; index < end; index++) if(inorder[index] == node->val) break;
      node->right = buildTree(inorder, postorder, index+1, end);
      node->left  = buildTree(inorder, postorder, start, index-1);
      return node;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      int len = inorder.size();
      for(int i = 0; i < len; i++) M[inorder[i]] = i;
      postindex = len-1;
      return buildTree(inorder, postorder, 0, len-1);
    }

    void printTree(TreeNode * root)
    {
      queue<TreeNode *> Q;
      Q.push(root);
      while(!Q.empty())
      {
        root = Q.front();
        Q.pop();
        if(root == nullptr) { cout << "null "; continue; }
        //if(root->left) 
          Q.push(root->left);
        //if(root->right) 
          Q.push(root->right);
        cout << root->val << " ";
      }
      cout << endl;
    }
};

int main()
{
  vector<int> In   = {9,3,15,20,7};
  vector<int> Post = {9,15,7,20,3};

  TreeNode * T = Solution().buildTree(In, Post);

  Solution().printTree(T);

  return 0;
}
