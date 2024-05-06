#include <iostream>
#include <vector>
#include <stack>
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
    stack<int> S;
public:
    int pairSum(ListNode* head) {
      if(head == nullptr) return 0;
      ListNode * slow = head;
      ListNode * fast = head->next;
      int maxpair = INT_MIN;

      while((fast != nullptr) && (fast->next != nullptr))
      {
        S.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
      }

      S.push(slow->val);
      slow = slow->next;

      while(slow != nullptr)
      {
        maxpair = max(maxpair, (slow->val + S.top()));
        S.pop();
        slow = slow->next;
      }

      return maxpair;
    }
};


int main()
{
  ListNode *M6 = new ListNode(5);
  ListNode *M5 = new ListNode(19, M6);
  ListNode *M4 = new ListNode(6, M5);
  ListNode *M3 = new ListNode(13, M4);
  ListNode *M2 = new ListNode(10, M3);
  ListNode *M1 = new ListNode(0, M2);

  Solution solution;
  cout << solution.pairSum(M1);
  cout<<endl;
  return 0;
}
