#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> vec( n , vector<int> (m, -1));
        vector<vector<bool> > seen(n, vector<bool>(m, false));
        int x=0, y=0, newX, newY;
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        int di = 0;
        while(head != nullptr)
        {
            //cout << "X: "<<x<<" Y: "<<y<<" Di: "<<di<<endl; 
            vec[x][y] = head->val;
            head = head->next;
            seen[x][y] = true;
            newX = x + dx[di];
            newY = y + dy[di];
            if((newX >=0)&&(newY >=0)&&(newX<n)&&(newY<m)&& !seen[newX][newY])
            {
              x = newX;
              y = newY;
            }
            else
            {
              di = (di+1)%4;
              x += dx[di];
              y += dy[di];
            }
            cout << "X: "<<x<<" Y: "<<y<<endl; 
        }
        return vec;
    }
};


int main()
{
  ListNode *M15 = new ListNode(5);
  ListNode *M14 = new ListNode(19, M15);
  ListNode *M13 = new ListNode(0);
  ListNode *M12 = new ListNode(5, M13);
  ListNode *M11 = new ListNode(5, M12);
  ListNode *M10 = new ListNode(2, M11);
  ListNode *M9  = new ListNode(4, M10);
  ListNode *M8  = new ListNode(9, M9);
  ListNode *M7  = new ListNode(7, M8);
  ListNode *M6  = new ListNode(1, M7);
  ListNode *M5  = new ListNode(8, M6);
  ListNode *M4  = new ListNode(6,  M5);
  ListNode *M3  = new ListNode(2, M4);
  ListNode *M2  = new ListNode(0, M3);
  ListNode *M1  = new ListNode(3,  M2);

  Solution solution;
  vector<vector<int>> SM = solution.spiralMatrix(5, 3, M1);
  
  for(int i =0; i < 3; i++)
  {
    for(int j = 0; j < 5; j++) cout << SM[i][j] << ", ";
    cout << endl; 
  }

  return 0;
}
