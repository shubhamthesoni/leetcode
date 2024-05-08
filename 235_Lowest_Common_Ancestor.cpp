#include <iostream>
#include <queue>

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
      queue<TreeNode *> Q;
      TreeNode * temp = root;
      TreeNode * lastMatch = root;

      while(true) 
      { 
        Q.push(temp); 
        if(temp->val > p->val) temp = temp->left; 
        else if(temp->val < p->val) temp = temp->right; 
        else break; 
      }

      temp = root;

      while(true) 
      {
        if(Q.size() == 1) return lastMatch;

        if(Q.front() != temp) { return lastMatch; }
        lastMatch = Q.front(); 
        Q.pop();

        if(temp->val > q->val) 
           temp = temp->left; 
        else if(temp->val < q->val) 
           temp = temp->right; 
        else return temp;
      }
      return root;
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
