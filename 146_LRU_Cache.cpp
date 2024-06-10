#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct ListNode2 {
    int val;
    ListNode2 *next;
    ListNode2 *prev;
    ListNode2() : val(0),  next(nullptr), prev(nullptr) {}
    ListNode2(int x) : val(x), next(nullptr), prev(nullptr) {}
    ListNode2(int x, ListNode2 *next, ListNode2 *prev) : val(x), next(next), prev(prev) {}
};

class LRUCache {
    map<int, ListNode2 *> M;
    map<ListNode2 *, int> N;
    ListNode2 * root;
    int totalSize;
    int currSize;

public:
    LRUCache(int capacity) {
      root = new ListNode2(-1);
      totalSize = capacity;
    }

    void insertCache(ListNode2 * node)
    {
      if(root->prev == nullptr) { root->next = node; root->prev = node; node->prev = root; node->next = root; }
      else { root->prev->next = node; node->prev = root->prev; node->next = root; root->prev = node; }
    }

    void deleteCache(ListNode2 * node)
    {
      ListNode2 * prev = node->prev;
      ListNode2 * next = node->next;
      if(prev == next) { root->prev = root->next = nullptr; }
      else if(prev == root) { root->next = node->next; node->next->prev = root; }
      else if(next == root) { root->prev = node->prev; node->prev->next = root; }
      else { prev->next = next; next->prev = prev; }
    }
    
    int get(int key) {
      if(M.find(key) == M.end()) return -1;
      ListNode2 * temp = M[key];
      if(temp == nullptr) return -1;
    
      int value = temp->val;
      deleteCache(temp);
      insertCache(temp);
      return value;
    }
    
    void put(int key, int value) {
      if((M.find(key) != M.end()) && (M[key] != nullptr))
      {
        ListNode2 * temp = M[key];
        temp->val = value;
        deleteCache(temp);
        insertCache(temp); 
        return;
      }

      ListNode2 * temp = nullptr;
      if(M.size() >= totalSize)
      {
        temp = root->next;
        M.erase(N[temp]);
        N.erase(temp);
        deleteCache(temp);
      }

      temp = new ListNode2(value);
      M[key] = temp;
      N[temp] = key;
      insertCache(temp);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int main()
{
  LRUCache L(2);
  L.put(1,1);
  L.put(2,2);
  cout << L.get(1) << endl;
  L.put(3,3);
  cout << L.get(2) << endl;
  L.put(4,4);
  cout << L.get(1) << endl;
  cout << L.get(3) << endl;
  cout << L.get(4) << endl;
  
  return 0;
}
