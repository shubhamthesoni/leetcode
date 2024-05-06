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
    ListNode* mergeNodes(ListNode* head)  
    {
      ListNode * curr = head;
      ListNode * temp = nullptr;
      ListNode * prev = nullptr;
      int S = 0;
      while(curr != nullptr)
      {
        if(curr->val == 0) {S=0; temp = curr->next; delete curr; curr = temp; }
        else 
        { 
          S += curr->val; 
          temp = curr->next; 
          curr->next = nullptr;
          if(temp->val != 0) { delete curr; curr = temp; }
          else { if(prev == nullptr) {head = curr; prev = curr; curr->val = S; } else { prev->next = curr; curr->val = S; prev = curr;} }
          curr = temp;
        } 
      }

      return head;
    }
};


int main()
{
  ListNode *M8 = new ListNode(0);
  ListNode *M7 = new ListNode(2, M8);
  ListNode *M6 = new ListNode(2, M7);
  ListNode *M5 = new ListNode(0, M6);
  ListNode *M4 = new ListNode(3, M5);
  ListNode *M3 = new ListNode(0, M4);
  ListNode *M2 = new ListNode(1, M3);
  ListNode *M1 = new ListNode(0, M2);

  Solution solution;
  ListNode * R = solution.mergeNodes(M1);

  while(R) {cout << R->val << ", "; R = R->next;}
  cout<<endl;
  return 0;
}
