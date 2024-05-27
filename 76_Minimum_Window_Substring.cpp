#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
#if 0
       int m = s.length();
       int n = t.length();
       string result;
       map<char, int> M;
       vector<int> H(m, 0);
       map<char, int> Q;
       for(char x: t) M[x]++;

       int left = 0;
       int right = 0;
       int uniq_count = 0;
       int min_left = 0;
       int min_Window = INT_MAX;
       while(right != m)
       {
         if(M.find(s.at(right)) != M.end())
         {
           H[right] = 1;
           Q[s.at(right)]++;
           if(Q[s.at(right)] <= M[s.at(right)]) uniq_count++;
           printf("Right : %d, Char : %c, Q: %d, M: %d, uniq_count: %d\n", right, s.at(right), Q[s.at(right)], M[s.at(right)], uniq_count);
         }
         if(uniq_count == n) 
         {
           if(min_Window > (right - left + 1)) { min_Window = right - left + 1; min_left = left; }
           
           cout << "Left before Loop " << left << endl;
           while(true)
           {
             if((H[left]==1) && (Q[s.at(left)] > M[s.at(left)]))
             {
               Q[s.at(left)]--;
               left++;
               if(min_Window > (right - left + 1)) { min_Window = right - left + 1; min_left = left; }
             }
             else if(H[left] == 0) 
             {
               left++;
               if(min_Window > (right - left + 1)) { min_Window = right - left + 1; min_left = left; }
             }
             else { Q[s.at(left)]--; left++;  break; }
           }
           uniq_count--;
           cout << "Left After Loop " << left << endl;
         }
         right++;
       }

       return (min_Window == INT_MAX) ? "" :s.substr(min_left, min_Window); 
#endif
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        std::vector<int> map(128, 0);
        int count = t.length();
        int start = 0, end = 0, minLen = INT_MAX, startIndex = 0;
        /// UPVOTE !
        for (char c : t) {
            map[c]++;
        }

        while (end < s.length()) {
            if (map[s[end++]]-- > 0) {
                count--;
            }

            while (count == 0) {
                if (end - start < minLen) {
                    startIndex = start;
                    minLen = end - start;
                }

                if (map[s[start++]]++ == 0) {
                    count++;
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};


int main()
{
  cout << Solution().minWindow("ABOBECEADBC", "ABC") << endl;
  return 0;
}

