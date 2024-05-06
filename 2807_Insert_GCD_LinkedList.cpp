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
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
      if(head == nullptr || head->next == nullptr) return head;

      ListNode * curr = head->next;
      ListNode * prev = head;

      while(curr != nullptr)
      {
        ListNode * N = new ListNode(__gcd(prev->val, curr->val), curr);
        prev->next = N;
        prev = curr;
        curr = curr->next;
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
  ListNode * R = solution.insertGreatestCommonDivisors(M1);

  while(R) {cout << R->val << ", "; R = R->next;}
  cout<<endl;
  return 0;
}
