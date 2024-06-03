#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {

    ListNode * mergeList(ListNode * first, ListNode * second)
    {
      ListNode * dummy = new ListNode(0);
      ListNode * head = dummy;

      while((first != nullptr) && (second != nullptr))
      {
        if(first->val <= second->val)
        {
          dummy->next = first;
          first = first->next;
          dummy = dummy->next;
        }
        else
        {
          dummy->next = second;
          second = second->next;
          dummy = dummy->next;
        }
      }


      while(first != nullptr) {  dummy->next = first; first = first->next; dummy = dummy->next; }
      while(second != nullptr) {  dummy->next = second; second = second->next; dummy = dummy->next; }

      dummy->next = nullptr;
      dummy = head;
      head = head->next;
      delete dummy;
      return head;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        vector<ListNode *> R;

	if(len == 0) return nullptr;
        if(len == 1) return lists[0];

        for(int i = 0; i < len; i++)
        {
            ListNode * L1 = lists[i];
            ListNode * L2 = ((i+1) == len) ? nullptr : lists[i+1];
     
            if(L2 == nullptr) R.push_back(L1);
            else R.push_back(mergeList(L1, L2));
            i++;
        }

        return  mergeKLists(R);
    }
};


int main()
{
  vector<ListNode *> V;
  ListNode * M3 = new ListNode(5);
  ListNode * M2 = new ListNode(4, M3);
  ListNode * M1 = new ListNode(1, M2);
  ListNode * N3 = new ListNode(4);
  ListNode * N2 = new ListNode(3, N3);
  ListNode * N1 = new ListNode(1, N2);
  ListNode * O2 = new ListNode(6);
  ListNode * O1 = new ListNode(2, O2);

  V.push_back(M1);
  V.push_back(N1);
  V.push_back(O1);

  ListNode * R = Solution().mergeKLists(V);
  while(R != nullptr) { cout << R->val << " "; R = R->next; }
  cout << endl;
  return 0;
}
