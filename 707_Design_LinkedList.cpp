#include<iostream>

using namespace std;

struct List 
{
    int val;
    struct List *next;
    List() : val(0), next(nullptr) {}
    List(int val) : val(val), next(nullptr) {}
    List(int val, List *next) : val(val), next(next) {}
};

class MyLinkedList {
    List * head = nullptr;
public:
    MyLinkedList() {
    }
    
    int get(int index) {
      List * temp = head;
      if(head == nullptr) return -1;
      while(index--) { if(temp == nullptr) return -1; temp = temp->next; }
      return (temp)?temp->val:-1;
    }
    
    void addAtHead(int val) {
      List * temp = new List(val);
      if(head == nullptr) {head = temp;}
      else { temp->next = head; head = temp;}
    }
    
    void addAtTail(int val) {
      List * temp = head;
      List * prev = nullptr;
      List * newNode = new List(val);

      if(head == nullptr) { head = newNode; return;}

      while(temp != nullptr) { prev = temp; temp = temp->next; }
      prev->next = newNode;
    }
    
    void addAtIndex(int index, int val) {
      if(index == 0) { addAtHead(val); return; }

      if(head == nullptr) return;

      List * temp = head;
      List * prev = nullptr;
      while(index--) { if(temp==nullptr) return; prev = temp; temp = temp->next; }
  
      List * newNode = new List(val);
      if(prev->next == nullptr) prev->next = newNode;
      else { newNode->next = prev->next; prev->next = newNode; }
    }
    
    void deleteAtIndex(int index) {
      List * dummy = nullptr;
      if(head == nullptr) return;
      if(index == 0) { dummy = head; head = head->next; delete dummy; return; }

      List * temp = head;
      List * prev = nullptr;
      while(index--) {if(temp == nullptr) return; prev = temp; temp=temp->next; }

      if(temp == nullptr) return;
      dummy = temp;
      prev->next = temp->next;
      delete dummy;

    }

    void display()
    {
      List * temp = head;
      cout << "Display :"<<endl;
      while(temp != nullptr) { cout << temp->val << " "; temp = temp->next; }
      cout <<endl;
    }
};


int main()
{
  MyLinkedList* obj = new MyLinkedList();
  obj->addAtHead(4);
  obj->display();
  cout << obj->get(1)<<endl;
  obj->addAtHead(1);
  obj->display();
  obj->addAtHead(5);
  obj->display();
  obj->deleteAtIndex(3);
  obj->display();
  obj->addAtHead(7);
  obj->display();
  cout << obj->get(3)<<endl;
  cout << obj->get(3)<<endl;
  cout << obj->get(3)<<endl;
  obj->addAtHead(1);
  obj->display();
  obj->deleteAtIndex(4);
  obj->display();

  return 0;

  obj->addAtTail(3);
  obj->display();
  obj->addAtIndex(1,2);
  obj->display();
  cout << obj->get(1)<<endl;
  obj->deleteAtIndex(1);
  obj->display();
  cout << obj->get(1)<<endl;
  return 0;
}
