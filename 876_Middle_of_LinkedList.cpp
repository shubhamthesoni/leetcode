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
    ListNode* middleNode(ListNode* head) {
      ListNode *p1 = head;
      ListNode *p2 = head;

      while(p2 != NULL && p2->next != NULL)
      {
        p1 = p1->next;
        p2 = p2->next->next;
      }
      return p1;
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
  //ListNode *N1 = new ListNode(1, N2);
  cout << solution.middleNode(N2)->val ;
  return 0;
}
