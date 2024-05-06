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
    ListNode* swapPairs(ListNode* head) 
    {
      if((head == nullptr)||(head->next == nullptr)) return head;

      ListNode * old = head;
      ListNode * prev = head;
      ListNode * next = head->next;

      while(next != nullptr)
      {
        prev->next = next->next;
        if(old==head) head = next; else old->next = next;
        next->next = prev;
        old = prev;
        prev = old->next;
        if((prev == nullptr) || (prev->next == nullptr)) break;
        next = prev->next;
      }

      return head;
    }
};


int main()
{
  ListNode *M5 = new ListNode(18);
  ListNode *M4 = new ListNode(3, M5);
  ListNode *M3 = new ListNode(10, M4);
  ListNode *M2 = new ListNode(6, M3);
  ListNode *M1 = new ListNode(18, M2);

  Solution solution;
  ListNode * R = solution.swapPairs(M1);

  while(R) {cout << R->val << ", "; R = R->next;}
  cout<<endl;
  return 0;
}
