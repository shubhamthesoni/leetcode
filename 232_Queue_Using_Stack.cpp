#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
    stack<int> S;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
      stack<int> T;
      while(!S.empty()) { T.push(S.top()); S.pop(); }
      S.push(x);
      while(!T.empty()) { S.push(T.top()); T.pop(); }
      return;
    }
    
    int pop() {
      int x = S.top();
      S.pop();
      return x;
    }
    
    int peek() {
      return S.top(); 
    }
    
    bool empty() {
      return S.empty();   
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


int main()
{
  MyQueue* obj = new MyQueue();
  obj->push(10);
  obj->push(11);
  cout << obj->peek() << endl;
  obj->push(12);
  cout << obj->pop() << endl;
  obj->push(13);
  cout << obj->pop() << endl;
  cout << obj->pop() << endl;
  cout << obj->pop() << endl;
  cout << obj->empty() << endl;

  return 0;
}
