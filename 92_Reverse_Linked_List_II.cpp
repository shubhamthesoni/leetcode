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
    void display(ListNode * T)
    {
      while(T != nullptr)
      {
        cout << T->val << " ";
        T = T->next;
      }
      cout << endl;
    }

    ListNode * reverse(ListNode * head, int right)
    {
      if((head == nullptr)||(head->next == nullptr)) return head;
      ListNode * next = head->next;
      ListNode * prev = head;
      int index = 1;      

      while((next != nullptr) && (right >= index))
      {
        prev->next = next->next; 
        next->next = head; 
        head = next;
        next = prev->next;
        display(head);
        index++;
      }
      return head;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      if((head == nullptr) || (head->next == nullptr)) return head;        
      ListNode * next = head;
      ListNode * prev = nullptr;
      ListNode * temp_head = nullptr;
      int index = 1;

      while((left!= index)&&(next!= nullptr))
      {
        prev = next;
        next = next->next;
        index++;
      }

      temp_head = reverse(next, right-left);
     
      if(prev == nullptr) head = temp_head;
      else prev->next = temp_head;

      return head;
    }
};

int main()
{
  ListNode * N5 = new ListNode(5);
  ListNode * N4 = new ListNode(4, N5);
  ListNode * N3 = new ListNode(3, N4);
  ListNode * N2 = new ListNode(2, N3);
  ListNode * N1 = new ListNode(1, N2);

  ListNode * T = Solution().reverseBetween(N1, 2, 4);
  while(T != nullptr)
  {
    cout << T->val << " ";
    T = T->next;
  }
  cout << endl;

  return 0;
}
