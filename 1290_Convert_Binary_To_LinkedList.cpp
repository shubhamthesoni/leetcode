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
    int getDecimalValue(ListNode* head) {
        int result = 0;
        while(head != nullptr)
        {
          result = result*2 + head->val;
          head = head->next;
        } 
        return result;
    }
};




int main()
{
  Solution solution;
  ListNode *N1 = new ListNode(1);
  ListNode *N2 = new ListNode(0, N1);
  ListNode *N3 = new ListNode(1, N2);
  cout << solution.getDecimalValue(N3);
  return 0;
}
