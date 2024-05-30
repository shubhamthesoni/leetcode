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
    ListNode* partition(ListNode* head, int x) {
        ListNode * before = nullptr;
        ListNode * after = nullptr;
        ListNode * next = head;
        ListNode * B = nullptr;
        ListNode * A = nullptr;
        ListNode * dummy = nullptr;
        while(next != nullptr)
        {
            if(next->val < x)
            {
                if(B == nullptr)
                {
                    before = next;
                    B = next;
                }
                else
                {
                    B->next = next;
                    B = B->next;
                }
            }
            else
            {
                if(A == nullptr)
                {
                    A = next;
                    after = next;
                }
                else
                {
                    A->next = next;
                    A = A->next;
                }
            }
            dummy = next->next;
            next->next = nullptr;
            next = dummy;
        }

        head = (before == nullptr) ? after:before;
        if(B != nullptr) {B->next = after; }
        return head;
    }
};
