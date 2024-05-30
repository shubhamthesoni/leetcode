#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct ListNode2 {
    int val;
    int key;
    ListNode2 *next;
    ListNode2 *prev;
    ListNode2() : val(0), next(nullptr) {}
    ListNode2(int x) : val(x), next(nullptr) {}
    ListNode2(int x, ListNode2 *next) : val(x), next(next){}
};

class LRUCache {
    map<int, ListNode2 *> M;
    ListNode2 * head;
    ListNode2 * last;
    int totalSize;

    void delet

public:
    LRUCache(int capacity) {
      head = nullptr;
      last = nullptr;
      totalSize = capacity;
    }
    
    int get(int key) {
      if(M.find(key) != M.end())
      {
        ListNode2 * temp = M[key];
        if(temp != last)
        {
          temp->prev->next = temp->next;
          temp->next->prev = temp->prev;
          temp->next = nullptr;
          temp->prev = last;
          last = temp;
        }
        return temp->val;
      }
      return -1;
    }
    
    void put(int key, int value) {
      if(M.find(key) != M.end())
      {
        ListNode2 * temp = M[key];
        temp->val = value;
        if(temp != last)
        {
          temp->prev->next = temp->next;
          temp->next->prev = temp->prev;
          temp->next = nullptr;
          temp->prev = last;
          last = temp;
        }
        return;
      }

      ListNode2 * temp = new ListNode2(value);
      if(M.size() >= totalSize)
      {
        ListNode2 * dummy = head;
        if(dummy == last) { last = nullptr; }
        delete dummy;
        head = head->next;
        if(head != nullptr) { head->prev = nullptr; }
      }

      {
        if(last == nullptr)
        {
          head = temp;
          last = temp;
        }  
        else
        {
          temp->next = nullptr;
          temp->prev = last;
          last = temp;
        }
      } 
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
