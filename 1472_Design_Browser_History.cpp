#include <iostream>
#include <list>

using namespace std;

class BrowserHistory {
      list<string> L;        
      list<string> :: iterator curr;
public:
    BrowserHistory(string homepage) {
      L.push_back(homepage);
      curr = L.begin();
    }
    
    void visit(string url) {
      L.erase(next(curr), L.end());
      L.push_back(url); 
      curr = prev(L.end());
    }
    
    string back(int steps) {
      while(steps--) { if(curr == L.begin()) break; curr = prev(curr); }
      return *curr;
    }
    
    string forward(int steps) {
      while(steps--) { if(next(curr) == L.end()) break; curr = next(curr); }
      return *curr;
    }

    void showlist() {
      list<string>::iterator it;
      for (it = L.begin(); it != L.end(); ++it)
        cout << '\t' << *it;
      cout << '\n';
    }

};


int main()
{
  BrowserHistory browser("leetcode.com");    browser.showlist();
  browser.visit("google.com");               browser.showlist();
  browser.visit("facebook.com");             browser.showlist();
  browser.visit("youtube.com");              browser.showlist();
  cout << browser.back(1) << endl;
  cout << browser.back(1) << endl;
  cout << browser.forward(1) << endl;
  browser.visit("linkedin.com");
  cout << browser.forward(2) << endl;
  cout << browser.back(2) << endl;
  cout << browser.back(7) << endl;

  return 0;
}
