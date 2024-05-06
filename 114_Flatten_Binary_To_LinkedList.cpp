#include<iostream>

using namespace std;

/**
 * Definition for a binary tree node.
*/
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
    TreeNode * inOrder(TreeNode *root)
    {
       if(root == nullptr) return nullptr;
       TreeNode * left = root->left;
       TreeNode * right = root->right;
       TreeNode * temp = root;

       root->left = nullptr;
       root->right = nullptr;
       if(left) { temp->right = inOrder(left); while(temp->right) temp = temp->right; }
       if(right) { temp->right = inOrder(right); }
       
       return root;
   }

    void flatten(TreeNode* root) {
       root = inOrder(root);     
    }
};

int main()
{
  TreeNode * T6 = new TreeNode(6);
  TreeNode * T5 = new TreeNode(5,nullptr,T6);
  TreeNode * T4 = new TreeNode(4);
  TreeNode * T3 = new TreeNode(3);
  TreeNode * T2 = new TreeNode(2, T3, T4);
  TreeNode * T1 = new TreeNode(1, T2, T5);
  
  Solution solution;
  solution.flatten(T1);

  while(T1!= nullptr) { cout<<T1->val<<" "; T1 = T1->right; }
  cout <<endl;

  return 0;
}
