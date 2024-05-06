#include <iostream>
#include <vector>
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
    ListNode* swapNodes(ListNode* head, int k)
    {
      ListNode * start = head;
      ListNode * end   = head;
      ListNode * last  = head;
      int temp = 0;

      while(--k)
      {
        start = start->next;
      }

      last = start->next;

      while(last != nullptr)
      {
        end = end->next;
        last = last->next;
      }

      temp = start->val;
      start->val = end->val;
      end->val = temp;

      return head;
    }
};


int main()
{
  ListNode *M5 = new ListNode(1);
  ListNode *M4 = new ListNode(3, M5);
  ListNode *M3 = new ListNode(10, M4);
  ListNode *M2 = new ListNode(6, M3);
  ListNode *M1 = new ListNode(18, M2);

  ListNode *T = M1;
  while(T) {cout << T->val << ", "; T = T->next;}
  cout<<endl;

  Solution solution;
  ListNode * R = solution.swapNodes(M1, 2);

  while(R) {cout << R->val << ", "; R = R->next;}
  cout<<endl;
  return 0;
}
