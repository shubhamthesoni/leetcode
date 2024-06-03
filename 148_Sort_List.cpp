#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode * mergeList(ListNode * first, ListNode * second)
    {
      ListNode * dummy = new ListNode(0);
      ListNode * head = dummy;

      while((first != nullptr) && (second != nullptr))
      {
        if(first->val <= second->val)
        {
          dummy->next = first;
          first = first->next;
          dummy = dummy->next;
        }
        else
        {
          dummy->next = second;
          second = second->next;
          dummy = dummy->next;
        }
      }
 

      while(first != nullptr) {  dummy->next = first; first = first->next; dummy = dummy->next; }
      while(second != nullptr) {  dummy->next = second; second = second->next; dummy = dummy->next; }

      dummy->next = nullptr;
      dummy = head;
      head = head->next;
      delete dummy;
      return head;
    }

public:
    ListNode* sortList(ListNode* head) {
      if((head == nullptr) || (head->next == nullptr)) return head; 
      ListNode * slow = head;
      ListNode * fast = head;
      ListNode * temp = nullptr;

      while((fast != NULL) && (fast->next != NULL))
      {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
      }
      temp->next = NULL;

      return mergeList(sortList(head), sortList(slow));
    }
};


int main()
{
  ListNode * N5 = new ListNode(0);
  ListNode * N4 = new ListNode(4, N5);
  ListNode * N3 = new ListNode(3, N4);
  ListNode * N2 = new ListNode(5, N3);
  ListNode * N1 = new ListNode(-1, N2);

  N1 = Solution().sortList(N1);

  while(N1 != nullptr) { cout << N1->val << " "; N1 = N1->next; }
  cout << endl;

  return 0;
}
