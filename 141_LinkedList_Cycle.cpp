#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>

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
    bool hasCycle(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};


int main()
{
  ListNode *M5 = new ListNode(5);
  ListNode *M4 = new ListNode(3, M5);
  ListNode *M32 = new ListNode(3, M4);
  ListNode *M3 = new ListNode(3, M4);
  ListNode *M2 = new ListNode(2, M3);
  ListNode *M1 = new ListNode(1, M2);

  M4->next = M2;

  Solution solution;
  cout << solution.hasCycle(M1);

  return 0;
}
