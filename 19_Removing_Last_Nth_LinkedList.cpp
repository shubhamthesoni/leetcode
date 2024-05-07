#include<iostream>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      if(head == nullptr) return head;
      ListNode * temp = head;
      ListNode * prev = nullptr;
      
      while(n--) { if(temp == nullptr) return head; temp = temp->next; }

      while(temp != nullptr)
      {
        prev = (prev==nullptr)?head:prev->next;
        temp = temp->next;
      }

      if(prev == nullptr) head = head->next;
      else prev->next = prev->next->next;

      return head;        
    }
};


int main()
{
  Solution solution;
  ListNode * M5 = new ListNode(5);
  ListNode * M4 = new ListNode(4, M5);
  ListNode * M3 = new ListNode(3, M4);
  ListNode * M2 = new ListNode(2, M3);
  ListNode * M1 = new ListNode(1, M2);

  ListNode * R = solution.removeNthFromEnd(M1, 2);
  while(R != nullptr) { cout << R->val<<" "; R = R->next; }
  cout << endl;

  return 0;
}
