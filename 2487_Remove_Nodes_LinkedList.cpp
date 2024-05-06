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

    ListNode *removeNodes(ListNode * head) {
      if(head == nullptr || head->next == nullptr) return head;
      head = reverseList(head);
      ListNode *temp = head;
      ListNode *dummy = head;
 
      while(temp->next != nullptr)
      {
        if(temp->val > temp->next->val)
        {
          dummy = temp->next;
          temp->next = temp->next->next;
          delete dummy;
        }
        else
        {
          temp = temp->next;
        }
      }

      return reverseList(head);
    }
};




int main()
{
  Solution solution;
  ListNode *N6 = new ListNode(6);
  ListNode *N5 = new ListNode(8);
  ListNode *N4 = new ListNode(3, N5);
  ListNode *N3 = new ListNode(13, N4);
  ListNode *N2 = new ListNode(2, N3);
  ListNode *N1 = new ListNode(5, N2);
  ListNode * Rev = solution.removeNodes(N1) ;

  while(Rev != NULL) { cout << "[]-> "<<Rev->val << endl; Rev = Rev->next;}

  return 0;
}
