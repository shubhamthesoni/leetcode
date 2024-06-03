#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {

public:
    void display(Node * N, int space=0)
    {
      if(N == nullptr) return;
      int S = space;
      while(S--) cout << " ";
      cout << N->val << "["<<N->isLeaf<<"]"<<endl;
      display(N->topLeft, space+4);
      display(N->topRight, space+4);
      display(N->bottomLeft, space+4);
      display(N->bottomRight, space+4);
      return;
    }

    Node* construct(vector<vector<int>>& grid, int i, int j, int size) {
      if(size == 1)
      {
        return new Node(grid[i][j], true);
      }

      Node * TL = construct(grid, i, j, size/2);
      Node * TR = construct(grid, i, j + size/2, size/2);
      Node * BL = construct(grid, i + size/2, j, size/2);
      Node * BR = construct(grid, i + size/2, j + size/2, size/2);
     
      if((TL->isLeaf == false) || (TR->isLeaf == false) ||
         (BL->isLeaf == false) || (BR->isLeaf == false))
      {
        return new Node(1, false, TL, TR, BL, BR);
      }

      int sum = TL->val + TR->val + BL->val + BR->val;
      if((sum == 0) || (sum == 4))
      {
        Node * newNode = new Node(TL->val, true);
        delete TL;
        delete TR;
        delete BL;
        delete BR;
        return newNode;
      }
      else
      {
        return new Node(1, false, TL, TR, BL, BR);
      }
    }

    Node* construct(vector<vector<int>>& grid) {
      int N = grid.size();
      return construct(grid, 0, 0, N);         
    }
};

int main()
{
  vector<vector<int>> G = {{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0}} ;
  Node * N = Solution().construct(G);

  Solution().display(N);

  return 0;
}
