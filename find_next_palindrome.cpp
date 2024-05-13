#include <iostream>
#include <string>

using namespace std;

string nextPalindrome(string S)
{
  int len = S.length();
 
  string num ;
  if(len%2 == 0) num = S.substr(0, len/2); else num = S.substr(0, len/2+1);
  
  string num2 = num;
  for(int i = len/2-1;  i >=0; i--)
    num2 += num2.at(i);
 
  if(stol(num2) <= stol(S)) num = to_string(stol(num)+1);

  num2 = num;
  for(int i = len/2-1;  i >=0; i--)
    num2 += num2.at(i);

  //cout << num2 <<endl;
 
  //cout << S<<endl;
  return num2;
}

int main()
{
  string S;
  getline(cin, S);

  for(int i = 0; i < 20; i++)
  {
    S = nextPalindrome(S);
    cout << S << endl;
  }

  return 0;
}
