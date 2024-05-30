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
    ListNode* rotateRight(ListNode* head, int k) {
       int len = 1;
       ListNode * next = head;
       ListNode * prev = nullptr;
       while(next->next != nullptr) { len++; next = next->next; }
       
       k = len - k%len;
       if(k == len) return head;

       next->next = head;
       next = head;

       while(--k) next = next->next;

       head = next->next;
       next->next = nullptr;

       return head;
    }
};


int main()
{
  ListNode * N8 = new ListNode(4);
  ListNode * N7 = new ListNode(4, N8);
  ListNode * N6 = new ListNode(4, N7);
  ListNode * N5 = new ListNode(5);
  ListNode * N4 = new ListNode(4, N5);
  ListNode * N3 = new ListNode(3, N4);
  ListNode * N2 = new ListNode(2, N3);
  ListNode * N1 = new ListNode(1, N2);

  int i = 10;

  ListNode * T = Solution().rotateRight(N1, 3);
  while(T != nullptr)
  {
    cout << T->val << " ";
    T = T->next;
    if(--i == 0) break;  
  }
  cout << endl;  
  return 0;
}
