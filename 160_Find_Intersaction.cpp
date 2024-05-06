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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      if(headA == nullptr || headB == nullptr) return nullptr;
      int sizeA = 0, sizeB = 0;
      ListNode *tempA = headA;
      ListNode *tempB = headB;
      while(tempA != nullptr) {sizeA++; tempA = tempA->next; }
      while(tempB != nullptr) {sizeB++; tempB = tempB->next; }

      if(sizeA > sizeB) 
      {
        int diff = sizeA - sizeB;
        while(diff--) headA = headA->next;
      }
      else if(sizeA < sizeB)
      {
        int diff = sizeB - sizeA;
        while(diff--) headB = headB->next;
      }

      while(headA != nullptr) { if(headA == headB) return headA; headA=headA->next; headB=headB->next;}
      return nullptr;
    }
};


int main()
{
  ListNode *M4 = new ListNode(4);
  ListNode *M3 = new ListNode(3, M4);
  ListNode *M2 = new ListNode(2, M3);
  ListNode *M1 = new ListNode(1, M2);

  ListNode *N3 = new ListNode(2, M3);

  Solution solution;
  ListNode *X = solution.getIntersectionNode(M1, N3);

  int count = 0; 
  while(X != nullptr) { cout << X->val << ", "; X=X->next; if(++count==10) break;}

  cout <<endl;
  return 0;
}
