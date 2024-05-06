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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
      ListNode * curr = list1;
      ListNode * temp = nullptr;
      b -= a;

      while(--a) curr = curr->next;

      temp = curr->next;
      curr->next = list2;

      while(list2->next != nullptr) list2 = list2->next; 
      while(b--) temp = temp->next;
      
      list2->next = temp->next;      

      return list1;
    }
};


int main()
{
  ListNode *M6 = new ListNode(5);
  ListNode *M5 = new ListNode(9, M6);
  ListNode *M4 = new ListNode(6, M5);
  ListNode *M3 = new ListNode(13, M4);
  ListNode *M2 = new ListNode(1, M3);
  ListNode *M1 = new ListNode(0, M2);

  ListNode *N3 = new ListNode(1002);
  ListNode *N2 = new ListNode(1001, N3);
  ListNode *N1 = new ListNode(1000, N2);

  Solution solution;
  ListNode * R = solution.mergeInBetween(M1, 3, 4, N1);

  while(R) {cout << R->val << ", "; R = R->next;}
  cout<<endl;
  return 0;
}
