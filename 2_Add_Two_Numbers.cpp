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
    ListNode* addTwoNumbers(ListNode * l1, ListNode * l2, int carry)
    {
      if((l1 == nullptr) && (l2 == nullptr))
      {
        if(carry == 1) return new ListNode(carry);
        else return nullptr;
      }
      else if(l1 == nullptr)
      {
        if(carry == 1)
        {
          l2->val += carry;
          carry = l2->val/10;
          l2->val = l2->val%10;
          l2->next = addTwoNumbers(nullptr, l2->next, carry);
        }
        return l2;
      }
      else if(l2 == nullptr)
      {
        if(carry == 1)
        {
          l1->val += carry;
          carry = l1->val/10;
          l1->val = l1->val%10;
          l1->next = addTwoNumbers(l1->next, nullptr, carry);
        }
        return l1;
      }
      else
      {
        l1->val += (l2->val + carry);
        carry = l1->val/10;
        l1->val = l1->val%10;
        l1->next = addTwoNumbers(l1->next, l2->next, carry);
        return l1;
      }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int carry = 0;
      return addTwoNumbers(l1, l2, carry); 
    }
};


int main()
{
  ListNode * M3 = new ListNode(3);
  ListNode * M2 = new ListNode(4, M3);
  ListNode * M1 = new ListNode(2, M2);

  ListNode * N3 = new ListNode(6);
  ListNode * N2 = new ListNode(6, N3);
  ListNode * N1 = new ListNode(5, N2);

  ListNode * R = Solution().addTwoNumbers(M1, N1);

  while(R != nullptr)
  {
    cout << R->val << " -> ";
    R = R->next;
  }

  cout << endl;
  return 0;
}
