#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }

    Node(int _val, Node * _next, Node * _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
      Node * temp = head;
      Node * newNode = nullptr;
      Node * dummy = nullptr;

      if(temp == nullptr) return nullptr;
      
      while(temp != nullptr)
      {
        newNode = new Node(temp->val);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = newNode->next;
      }

      temp = head;
      dummy = temp->next;
      while(temp != nullptr)
      {
        newNode = temp->next;
        newNode->random = (temp->random != nullptr)? (temp->random->next) : nullptr;
        temp = newNode->next;
      }
    
      temp = head;
      while(temp != nullptr)
      {
        newNode = temp->next;
        temp->next = newNode->next;
        temp = temp->next;
        newNode->next = (temp == nullptr)? nullptr:(temp->next);
      }

      return dummy;
    }
};


int main()
{
  Node * N5 = new Node(1);
  Node * N4 = new Node(10, N5, nullptr);
  Node * N3 = new Node(11, N4, N5);
  Node * N2 = new Node(13, N3, nullptr);
  Node * N1 = new Node(7, N2, nullptr);
  N2->random = N1;
  N4->random = N3;
  N5->random = N1;

  printf("%d[%p, %p] -> %d[%p, %p] -> %d[%p, %p]  -> %d[%p, %p] -> %d[%p, %p]\n", N1->val, N1, N1->random, N2->val, N2, N2->random, N3->val, N3, N3->random, N4->val, N4, N4->random, N5->val, N5, N5->random);

  Node * temp = Solution().copyRandomList(N1);

  while(temp != nullptr)
  {
    printf("%d[%p, %p] \n", temp->val, temp, temp->random);
    temp = temp->next;
  }
  return 0;
}
