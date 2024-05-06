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
    ListNode* reverseList(ListNode* head) {
      ListNode *p1 = head, *p2 = nullptr;
      while(p1->next != nullptr)
      {
        p2 = p1->next;
        p1->next = p2->next;
        p2->next = head;
        head = p2;
      }
      return head;
    }
};




int main()
{
  Solution solution;
  ListNode *N6 = new ListNode(6);
  ListNode *N5 = new ListNode(5, N6);
  ListNode *N4 = new ListNode(4, N5);
  ListNode *N3 = new ListNode(3, N4);
  ListNode *N2 = new ListNode(2, N3);
  ListNode *N1 = new ListNode(1, N2);
  ListNode * Rev = solution.reverseList(N1) ;

  while(Rev != NULL) { cout << "[]-> "<<Rev->val << endl; Rev = Rev->next;}

  return 0;
}
