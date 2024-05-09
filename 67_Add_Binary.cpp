#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
      string R;
      int lenA = a.length()-1;
      int lenB = b.length()-1;
      bool carry = 0;      

      while(true)
      {
        int sum = ((lenA >=0)?(a[lenA--]-'0'):0) + ((lenB >=0)?(b[lenB--]-'0'):0) + carry;
        carry = sum & 0x02;
        R.append(to_string(sum & 0x01));
        //cout << "Sum : "<<sum<<" R: "<<R<<" Carry: "<<carry<<endl;
        if((lenA <0) && (lenB < 0)) break;
      }
      if(carry) R.append(to_string(1)); // = to_string(1)+R;

      reverse(R.begin(), R.end());
      return R;        
    }
};


int main()
{
  Solution solution;
  cout << solution.addBinary("11", "1") << endl;
  cout << solution.addBinary("1010", "1011") << endl;
  return 0;
}
