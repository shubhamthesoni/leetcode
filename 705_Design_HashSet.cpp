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
    ListNode(int x, ListNode *next) : val(x), next(next) { cout << "New Node Allocated with value "<<x<<endl;}
};

class MyHashSet {

    ListNode *head = nullptr;

public:
    MyHashSet() {
    }
    
    void add(int key) {
      ListNode * temp = head;
      ListNode * prev = nullptr;
      if(temp == nullptr) 
      {
        ListNode * newnode = new ListNode(key);
        head = newnode;
        return;
      }

      while(temp!= nullptr)
      {
        if(temp->val == key) return;
        if(temp->val > key)
        {
          ListNode * newnode = new ListNode(key, temp);
          if(prev == nullptr) { head = newnode; } else {prev->next = newnode;}
          return;
        }
        prev = temp;
        temp = temp->next;
      }

      if(temp == nullptr) 
      { 
        ListNode * newnode = new ListNode(key);
        if(prev == nullptr) { head = newnode; } else {prev->next = newnode;}
        return;
      }

    }
    
    void remove(int key) {
       ListNode * temp = head;
       ListNode * prev = nullptr;
       while(temp != nullptr)
       {
         cout << "Inside Remove : "<< temp->val << endl;
         if(temp->val == key)
         {
           if(prev == nullptr) {head = temp->next; }
           else { prev->next = temp->next;}
           delete temp;
           return;
         }
         if(temp->val > key) return ;
         prev = temp;
         temp = temp->next;
       }

 
       return;
        
    }
    
    bool contains(int key) {
       ListNode * temp = head;
       while(temp != nullptr)
       {
         if(temp->val == key) return true;
         temp = temp->next;
       } 
       return false;
    }
    void display() {
      ListNode * temp = head;
      cout << "DISPLAY:"<<endl;
      int count = 0;
      while(temp != nullptr) {cout << "List : "<< temp->val<<endl; temp = temp->next; if(++count == 10) break;}
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */


int main()
{
  MyHashSet * obj = new MyHashSet();
  obj->add(9);
  obj->display();
  obj->remove(19);
  obj->display();
  obj->add(14);
  obj->display();
  obj->remove(19);
  obj->display();
  obj->remove(9);
  obj->display();
  obj->add(0);
  obj->display();
  obj->add(3);
  obj->display();
  obj->add(4);
  obj->display();
  obj->add(0);
  obj->display();
  obj->remove(9);
  obj->display();

/*
  obj->display();
  obj->add(2);
  obj->display();
  cout << obj->contains(1) << endl;
  cout << obj->contains(3) << endl;
  obj->add(2);
  obj->display();
  cout << obj->contains(2) << endl;
  obj->remove(2);
  obj->add(2);
  obj->add(3);
  obj->remove(2);
  obj->display();
  cout << obj->contains(2) << endl;
*/
  return 0;
}
