#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>

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
    ListNode* deleteDuplicates(ListNode* head)
    {
      ListNode * curr = (head!= nullptr) ? head->next: head;
      ListNode * prev = head;

      while(curr != nullptr)
      {
        if(curr->val == prev->val)
        {
          prev->next = curr->next;
          delete curr;
          curr = prev->next;
          continue;
        }
        prev = curr;
        curr = curr->next;
      }
      return head;
    }
};


int main()
{
  ListNode *M5 = new ListNode(5);
  ListNode *M4 = new ListNode(3, M5);
  ListNode *M32 = new ListNode(3, M4);
  ListNode *M3 = new ListNode(3, M32);
  ListNode *M2 = new ListNode(2, M3);
  ListNode *M1 = new ListNode(1, M2);

  Solution solution;
  ListNode * R = solution.deleteDuplicates(M1);

  while(R) {cout << R->val << ", "; R = R->next;}
  cout<<endl;
  return 0;
}
