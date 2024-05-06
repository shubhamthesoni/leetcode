#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.length();
        int n2 = version2.length();

        int v1 = 0, v2 = 0;
        for(int i =0, j =0; (i < v1) || (j < v2) ; i++, j++)
        {
          while((i<v1) && (version1[i] != '.'))
          {
            v1 = v1*10 + (version1[i] - '0'); i++;
          }
          while((j<v2) && (version2[j] != '.'))
          {
            v2 = v2*10 + (version2[j] - '0'); j++;
          }

          if( v1 != v2) return (v1>v2)?1:-1;

          v1 = v2 = 0;
        }

        return 0;


#if 0
        int v1, v2;
        v1 = v2 = 0;
        if((version1.empty()) && (version2.empty() )) return 0;

        if(version1.find('.') != string::npos)
        {
          v1 = stoi(version1.substr(0, version1.find('.')));
          version1.erase(0, version1.find('.') + 1);
        }
        else
        {
          v1 = stoi(version1);
          version1="";
        }

        if(version2.find('.') != string::npos)
        {
          v2 = stoi(version2.substr(0, version2.find('.')));
          version2.erase(0, version2.find('.') + 1);
        }
        else
        {
          v2 = stoi(version2);
          version2="";
        }
        

        if(v1 != v2) return (v1-v2);

        return compareVersion(version1, version2);
#endif

    }
};



int main()
{
  Solution solution;
  cout << solution.compareVersion("1.01","1.001");
  return 0;
}
