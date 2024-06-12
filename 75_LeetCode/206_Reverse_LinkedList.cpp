/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      ListNode *p1 = head, *p2 = nullptr;
      if(head == nullptr) return head;
      while(p1->next != nullptr)
      {
        p2 = p1->next;
        p1->next = p2->next;
        p2->next = head;
        head = p2;
      }
      return head;
        
    }
};
