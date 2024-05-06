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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
      ListNode * head = new ListNode(0);
      ListNode * curr = head;
      ListNode * temp = nullptr;

      while(list1 != nullptr && list2 != nullptr)
      {
        cout << "Comparing List1 "+ to_string(list1->val) + " with List2 " + to_string(list2->val)<<endl;
        if(list1->val < list2->val) 
        {
          curr->next = list1;
          list1 = list1->next;
        }
        else
        {
          curr->next = list2;
          list2 = list2->next;
        }
        curr = curr->next;
      }

      curr->next = (list1 != nullptr) ? list1: list2;
      return head->next;
    }
};


int main()
{
  ListNode *N1 = new ListNode(4);
  ListNode *N2 = new ListNode(3, N1);
  ListNode *N3 = new ListNode(1, N2);

  ListNode *M1 = new ListNode(4);
  ListNode *M2 = new ListNode(2, M1);
  ListNode *M3 = new ListNode(1, M2);

  Solution solution;
  ListNode *X = solution.mergeTwoLists(M3, N3);

  int count = 0; 
  while(X != nullptr) { cout << X->val << ", "; X=X->next; if(++count==10) break;}

  cout <<endl;
  return 0;
}
