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
public:
    ListNode* deleteDuplicates(ListNode* head) {
       if((head == nullptr)||(head->next == nullptr)) return head;

       ListNode * dummy = new ListNode(0, head);
       ListNode * prev = dummy;

       while(head != nullptr)
       {
         if((head->next != nullptr) && (head->val == head->next->val))
         {
           while((head->next != nullptr) && (head->val == head->next->val)) head = head->next;
           prev->next = head->next;
         }
         else
         {
           prev = prev->next;
         }
         head = head->next;
       }

       return dummy->next;
#if 0
       while(next->next != nullptr)
       {
         if(next->val == next->next->val)
         {
           del = true;
           next->next = next->next->next;
           continue;
         }
         if(del)
         {
           del = false;
           if(prev == nullptr)
           {
             head = next->next;
             next = head;
           }
           else
           {
             prev->next = next->next;
             next = prev->next;
           }
         }
         else
         {
           prev = next;
           next = next->next;
         }
       }

       if(del)
       {
         if(prev == nullptr)
         {
           head = next->next;
         }
         else
         {
           prev->next = next->next;
         }
       }

       return head;
#endif

    }
};

int main()
{
  ListNode * N8 = new ListNode(4);
  ListNode * N7 = new ListNode(4, N8);
  ListNode * N6 = new ListNode(4, N7);
  ListNode * N5 = new ListNode(3, N6);
  ListNode * N4 = new ListNode(2, N5);
  ListNode * N3 = new ListNode(2, N4);
  ListNode * N2 = new ListNode(1, N3);
  ListNode * N1 = new ListNode(1, N2);
  
  ListNode * T = Solution().deleteDuplicates(N1);
  while(T != nullptr)
  { 
    cout << T->val << " ";
    T = T->next;
  }
  cout << endl;

  return 0;
}
