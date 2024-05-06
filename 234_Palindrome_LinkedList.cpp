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
    bool isPalindrome(ListNode* head) {
      ListNode * temp = head;
      stack<int> S;
      while(temp != nullptr) { S.push(temp->val); temp = temp->next; }
      temp = head;
      while(temp != nullptr)
      {
        if(temp->val != S.top()) return false;
        temp = temp->next; S.pop();
      }
      return true;
    }
};


int main()
{
  ListNode *M4 = new ListNode(1);
  ListNode *M3 = new ListNode(3, M4);
  ListNode *M2 = new ListNode(2, M3);
  ListNode *M1 = new ListNode(1, M2);

  Solution solution;
  cout << solution.isPalindrome(M1);

  return 0;
}
