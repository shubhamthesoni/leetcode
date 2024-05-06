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
    ListNode* removeElements(ListNode* head, int val) 
    {
      ListNode * curr = head;
      ListNode * prev = nullptr;

      while(curr != nullptr)
      {
        if(curr->val == val)
        {
          if(prev == nullptr) head = curr->next; else prev->next = curr->next;
          delete curr;
          if(prev == nullptr) curr = head; else curr = prev->next;
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
  ListNode *M5 = new ListNode(2);
  ListNode *M4 = new ListNode(2, M5);
  ListNode *M3 = new ListNode(3, M4);
  ListNode *M2 = new ListNode(2, M3);
  ListNode *M1 = new ListNode(2, M2);

  Solution solution;
  ListNode * R = solution.removeElements(M1, 2);

  while(R) {cout << R->val << ", "; R = R->next;}
  cout<<endl;
  return 0;
}
