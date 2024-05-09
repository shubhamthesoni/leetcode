#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode * left, TreeNode * right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

#if 0
      TreeNode * temp = root;
      TreeNode * lastMatch = root;
      vector<TreeNode *> V;
      int index = 0;

      while(true) 
      { 
        V.push_back(temp); 
        if(temp->val > p->val) temp = temp->left; 
        else if(temp->val < p->val) temp = temp->right; 
        else break; 
      }

      temp = root;

      while(true) 
      {
        if(V[index] != temp) return V[index-1];

        if(temp->val > q->val) temp = temp->left;
        else if(temp->val < q->val) temp = temp->right;
        else break;

        if(index == V.size()-1) break;
        index++;
      }
      
      return V[index];
#endif
      if(root == nullptr) return root;
      if((p->val > root->val) && (q->val > root->val)) return lowestCommonAncestor(root->right, p, q);
      else if ((p->val < root->val) && (q->val < root->val)) return lowestCommonAncestor(root->left, p, q);
      else return root;

    }
};


int main()
{
  TreeNode * N3 = new TreeNode(3);
  TreeNode * N5 = new TreeNode(5);
  TreeNode * N4 = new TreeNode(4, N3, N5);

  TreeNode * N0 = new TreeNode(0);
  TreeNode * N2 = new TreeNode(2, N0, N4);
  
  TreeNode * N7 = new TreeNode(7);
  TreeNode * N9 = new TreeNode(9);
  TreeNode * N8 = new TreeNode(8, N7, N9);

  TreeNode * N6 = new TreeNode(6, N2, N8);

  Solution solution;
  cout << solution.lowestCommonAncestor(N6, N2, N8)->val << endl;
  cout << solution.lowestCommonAncestor(N6, N2, N4)->val << endl;
  cout << solution.lowestCommonAncestor(N6, N2, N0)->val << endl;
  return 0;
}
